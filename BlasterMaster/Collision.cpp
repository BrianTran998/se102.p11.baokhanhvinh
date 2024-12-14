#include "Collision.h"
#include "GameObject.h"

#include "debug.h"

#define BLOCK_PUSH_FACTOR 0.01f

CCollision *CCollision::__instance = NULL;

int CCollisionEvent::WasCollided()
{
	return t >= 0.0f && t <= 1.0f && obj->IsDirectionColliable(nx, ny) == 1;
}

CCollision *CCollision::GetInstance()
{
	if (__instance == NULL)
		__instance = new CCollision();
	return __instance;
}

/*
	SweptAABB - Thuật toán kiểm tra va chạm giữa hai hình chữ nhật (AABB) khi một đối tượng di chuyển
*/
void CCollision::SweptAABB(
	float movingLeft, float movingTop, float movingRight, float movingBottom, // Thông tin hộp bao của đối tượng di chuyển (left, top, right, bottom)
	float vX, float vY,														  // Vận tốc thay đổi của đối tượng di chuyển (vX, vY)
	float staticLeft, float staticTop, float staticRight, float staticBottom, // Thông tin hộp bao của đối tượng cố định (left, top, right, bottom)
	float &collisionTime, float &normalX, float &normalY)					  // Tham số trả về thời gian va chạm (collisionTime) và vector pháp tuyến (normalX, normalY)
{
	// Khởi tạo các biến để tính toán va chạm
	float entryX, exitX, entryTimeX, exitTimeX;
	float entryY, exitY, entryTimeY, exitTimeY;

	float timeEntry;
	float timeExit;

	// Khởi tạo giá trị ban đầu cho thời gian va chạm (collisionTime) và vector pháp tuyến normalX, normalY
	collisionTime = -1.0f; // Không có va chạm ban đầu
	normalX = normalY = 0;

	//
	// Broad-phase test (Kiểm tra va chạm sơ bộ)
	//
	// Tính toán vị trí của đối tượng di chuyển sau khi áp dụng vận tốc vX, vY
	float movingLeftAfterVelocity = vX > 0 ? movingLeft : movingLeft + vX;
	float movingTopAfterVelocity = vY > 0 ? movingTop : movingTop + vY;
	float movingRightAfterVelocity = vX > 0 ? movingRight + vX : movingRight;
	float movingBottomAfterVelocity = vY > 0 ? movingBottom + vY : movingBottom;

	// Nếu hộp bao của đối tượng di chuyển không giao với hộp bao của đối tượng cố định thì không có va chạm
	if (movingRightAfterVelocity < staticLeft || movingLeftAfterVelocity > staticRight || movingBottomAfterVelocity < staticTop || movingTopAfterVelocity > staticBottom)
		return;

	// Nếu đối tượng di chuyển không thay đổi vị trí (vX == 0 && vY == 0), không cần kiểm tra va chạm
	if (vX == 0 && vY == 0)
		return; // Không di chuyển, rõ ràng không có va chạm

	// Tính toán thời gian vào và ra theo trục X (horizontal)
	if (vX > 0) // Nếu đối tượng di chuyển sang phải
	{
		entryX = staticLeft - movingRight; // Thời gian vào của đối tượng di chuyển theo trục X
		exitX = staticRight - movingLeft;  // Thời gian ra của đối tượng di chuyển theo trục X
	}
	else if (vX < 0) // Nếu đối tượng di chuyển sang trái
	{
		entryX = staticRight - movingLeft; // Thời gian vào của đối tượng di chuyển theo trục X
		exitX = staticLeft - movingRight;  // Thời gian ra của đối tượng di chuyển theo trục X
	}

	// Tính toán thời gian vào và ra theo trục Y (vertical)
	if (vY > 0) // Nếu đối tượng di chuyển xuống dưới
	{
		entryY = staticTop - movingBottom; // Thời gian vào của đối tượng di chuyển theo trục Y
		exitY = staticBottom - movingTop;  // Thời gian ra của đối tượng di chuyển theo trục Y
	}
	else if (vY < 0) // Nếu đối tượng di chuyển lên trên
	{
		entryY = staticBottom - movingTop; // Thời gian vào của đối tượng di chuyển theo trục Y
		exitY = staticTop - movingBottom;  // Thời gian ra của đối tượng di chuyển theo trục Y
	}

	// Xử lý trường hợp đối tượng không di chuyển trên trục X (vX == 0)
	if (vX == 0)
	{
		entryTimeX = -9999999.0f; // Không có va chạm trong trường hợp này
		exitTimeX = 99999999.0f;
	}
	else
	{
		entryTimeX = entryX / vX; // Tính thời gian va chạm trên trục X
		exitTimeX = exitX / vX;	  // Tính thời gian rời đi trên trục X
	}

	// Xử lý trường hợp đối tượng không di chuyển trên trục Y (vY == 0)
	if (vY == 0)
	{
		entryTimeY = -99999999999.0f; // Không có va chạm trong trường hợp này
		exitTimeY = 99999999999.0f;
	}
	else
	{
		entryTimeY = entryY / vY; // Tính thời gian va chạm trên trục Y
		exitTimeY = exitY / vY;	  // Tính thời gian rời đi trên trục Y
	}

	// Nếu thời gian va chạm và thời gian rời đi đều không hợp lệ, thì không có va chạm
	if ((entryTimeX < 0.0f && entryTimeY < 0.0f) || entryTimeX > 1.0f || entryTimeY > 1.0f)
		return;

	// Xác định thời gian va chạm và thời gian rời đi thực tế
	timeEntry = max(entryTimeX, entryTimeY); // Thời gian va chạm là thời gian vào muộn hơn giữa trục X và Y
	timeExit = min(exitTimeX, exitTimeY);	 // Thời gian rời đi là thời gian ra sớm nhất giữa trục X và Y

	// Nếu thời gian va chạm muộn hơn thời gian rời đi, không có va chạm
	if (timeEntry > timeExit)
		return;

	// Nếu có va chạm, lưu thời gian va chạm vào collisionTime
	collisionTime = timeEntry;

	// Kiểm tra xem va chạm là theo chiều ngang (X) hay chiều dọc (Y)
	if (entryTimeX > entryTimeY)
	{
		normalY = 0.0f;							   // Va chạm theo chiều ngang, không thay đổi theo trục Y
		vX > 0 ? normalX = -1.0f : normalX = 1.0f; // Nếu đối tượng di chuyển sang phải, va chạm với bên trái; nếu di chuyển sang trái, va chạm với bên phải
	}
	else
	{
		normalX = 0.0f;							   // Va chạm theo chiều dọc, không thay đổi theo trục X
		vY > 0 ? normalY = -1.0f : normalY = 1.0f; // Nếu đối tượng di chuyển xuống dưới, va chạm với phía trên; nếu di chuyển lên trên, va chạm với phía dưới
	}
}

/*
	Extension of original SweptAABB to deal with two moving objects
*/
LPCOLLISIONEVENT CCollision::SweptAABB(LPGAMEOBJECT objSrc, DWORD dt, LPGAMEOBJECT objDest)
{
	float sl, st, sr, sb; // static object bbox
	float ml, mt, mr, mb; // moving object bbox
	float t, nx, ny;

	float mvx, mvy;
	objSrc->GetSpeed(mvx, mvy);
	float mdx = mvx * dt;
	float mdy = mvy * dt;

	float svx, svy;
	objDest->GetSpeed(svx, svy);
	float sdx = svx * dt;
	float sdy = svy * dt;

	//
	// NOTE: new m speed = original m speed - collide object speed
	//
	float dx = mdx - sdx;
	float dy = mdy - sdy;

	objSrc->GetBoundingBox(ml, mt, mr, mb);
	objDest->GetBoundingBox(sl, st, sr, sb);

	SweptAABB(
		ml, mt, mr, mb,
		dx, dy,
		sl, st, sr, sb,
		t, nx, ny);

	CCollisionEvent *e = new CCollisionEvent(t, nx, ny, dx, dy, objDest, objSrc);
	return e;
}

/*
	Calculate potential collisions with the list of colliable objects

	coObjects: the list of colliable objects
	coEvents: list of potential collisions
*/
void CCollision::Scan(LPGAMEOBJECT objSrc, DWORD dt, vector<LPGAMEOBJECT> *objDests, vector<LPCOLLISIONEVENT> &coEvents)
{
	for (UINT i = 0; i < objDests->size(); i++)
	{
		LPCOLLISIONEVENT e = SweptAABB(objSrc, dt, objDests->at(i));

		if (e->WasCollided() == 1)
			coEvents.push_back(e);
		else
			delete e;
	}

	// std::sort(coEvents.begin(), coEvents.end(), CCollisionEvent::compare);
}

void CCollision::Filter(LPGAMEOBJECT objSrc,
						vector<LPCOLLISIONEVENT> &coEvents,
						LPCOLLISIONEVENT &colX,
						LPCOLLISIONEVENT &colY,
						int filterBlock = 1, // 1 = only filter block collisions, 0 = filter all collisions
						int filterX = 1,	 // 1 = process events on X-axis, 0 = skip events on X
						int filterY = 1)	 // 1 = process events on Y-axis, 0 = skip events on Y
{
	float min_tx, min_ty;

	min_tx = 1.0f;
	min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT c = coEvents[i];
		if (c->isDeleted)
			continue;
		if (c->obj->IsDeleted())
			continue;

		// ignore collision event with object having IsBlocking = 0 (like coin, mushroom, etc)
		if (filterBlock == 1 && !c->obj->IsBlocking())
		{
			continue;
		}

		if (c->t < min_tx && c->nx != 0 && filterX == 1)
		{
			min_tx = c->t;
			min_ix = i;
		}

		if (c->t < min_ty && c->ny != 0 && filterY == 1)
		{
			min_ty = c->t;
			min_iy = i;
		}
	}

	if (min_ix >= 0)
		colX = coEvents[min_ix];
	if (min_iy >= 0)
		colY = coEvents[min_iy];
}

/*
 *  Simple/Sample collision framework
 *  NOTE: Student might need to improve this based on game logic
 */
void CCollision::Process(LPGAMEOBJECT objSrc, DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	LPCOLLISIONEVENT colX = NULL;
	LPCOLLISIONEVENT colY = NULL;

	coEvents.clear();

	if (objSrc->IsCollidable())
	{
		Scan(objSrc, dt, coObjects, coEvents);
	}

	// No collision detected
	if (coEvents.size() == 0)
	{
		objSrc->OnNoCollision(dt);
	}
	else
	{
		Filter(objSrc, coEvents, colX, colY);

		float x, y, vx, vy, dx, dy;
		objSrc->GetPosition(x, y);
		objSrc->GetSpeed(vx, vy);
		dx = vx * dt;
		dy = vy * dt;

		if (colX != NULL && colY != NULL)
		{
			if (colY->t < colX->t) // was collision on Y first ?
			{
				y += colY->t * dy + colY->ny * BLOCK_PUSH_FACTOR;
				objSrc->SetPosition(x, y);

				objSrc->OnCollisionWith(colY);

				//
				// see if after correction on Y, is there still a collision on X ?
				//
				LPCOLLISIONEVENT colX_other = NULL;

				//
				// check again if there is true collision on X
				//
				colX->isDeleted = true; // remove current collision event on X

				// replace with a new collision event using corrected location
				coEvents.push_back(SweptAABB(objSrc, dt, colX->obj));

				// re-filter on X only
				Filter(objSrc, coEvents, colX_other, colY, /*filterBlock = */ 1, 1, /*filterY=*/0);

				if (colX_other != NULL)
				{
					x += colX_other->t * dx + colX_other->nx * BLOCK_PUSH_FACTOR;
					objSrc->OnCollisionWith(colX_other);
				}
				else
				{
					x += dx;
				}
			}
			else // collision on X first
			{
				x += colX->t * dx + colX->nx * BLOCK_PUSH_FACTOR;
				objSrc->SetPosition(x, y);

				objSrc->OnCollisionWith(colX);

				//
				// see if after correction on X, is there still a collision on Y ?
				//
				LPCOLLISIONEVENT colY_other = NULL;

				//
				// check again if there is true collision on Y
				//
				colY->isDeleted = true; // remove current collision event on Y

				// replace with a new collision event using corrected location
				coEvents.push_back(SweptAABB(objSrc, dt, colY->obj));

				// re-filter on Y only
				Filter(objSrc, coEvents, colX, colY_other, /*filterBlock = */ 1, /*filterX=*/0, /*filterY=*/1);

				if (colY_other != NULL)
				{
					y += colY_other->t * dy + colY_other->ny * BLOCK_PUSH_FACTOR;
					objSrc->OnCollisionWith(colY_other);
				}
				else
				{
					y += dy;
				}
			}
		}
		else if (colX != NULL)
		{
			x += colX->t * dx + colX->nx * BLOCK_PUSH_FACTOR;
			y += dy;
			objSrc->OnCollisionWith(colX);
		}
		else if (colY != NULL)
		{
			x += dx;
			y += colY->t * dy + colY->ny * BLOCK_PUSH_FACTOR;
			objSrc->OnCollisionWith(colY);
		}
		else // both colX & colY are NULL
		{
			x += dx;
			y += dy;
		}

		objSrc->SetPosition(x, y);
	}

	//
	// Scan all non-blocking collisions for further collision logic
	//
	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT e = coEvents[i];
		if (e->isDeleted)
			continue;
		if (e->obj->IsBlocking())
			continue; // blocking collisions were handled already, skip them

		objSrc->OnCollisionWith(e);
	}

	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
}
