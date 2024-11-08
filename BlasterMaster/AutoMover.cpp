#include "AutoMover.h"
#include "Game.h"

CAutoMover::CAutoMover(float x, float y):CGameObject(x, y)
{
	this->ax = 0;
	this->ay = AUTOMOVER_GRAVITY;
	die_start = -1;
	SetState(AUTOMOVER_STATE_WALKING);
}

void CAutoMover::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	// if (state == AUTOMOVER_STATE_DIE)
	// {
	// 	left = x - AUTOMOVER_BBOX_WIDTH/2;
	// 	top = y - AUTOMOVER_BBOX_HEIGHT_DIE/2;
	// 	right = left + AUTOMOVER_BBOX_WIDTH;
	// 	bottom = top + AUTOMOVER_BBOX_HEIGHT_DIE;
	// }
	// else
	// { 
	// 	left = x - AUTOMOVER_BBOX_WIDTH/2;
	// 	top = y - AUTOMOVER_BBOX_HEIGHT/2;
	// 	right = left + AUTOMOVER_BBOX_WIDTH;
	// 	bottom = top + AUTOMOVER_BBOX_HEIGHT;
	// }
}

void CAutoMover::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

// void CAutoMover::OnCollisionWith(LPCOLLISIONEVENT e)
// {
// 	if (!e->obj->IsBlocking()) return; 
// 	if (dynamic_cast<CAutoMover*>(e->obj)) return; 

// 	if (e->ny != 0 )
// 	{
// 		vy = 0;
// 	}
// 	else if (e->nx != 0)
// 	{
// 		vx = -vx;
// 	}
// }

void CAutoMover::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{

	x += vx * dt;
	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - AUTOMOVER_BBOX_WIDTH)
	{
		vx = -vx;
		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - AUTOMOVER_BBOX_WIDTH)
		{
			x = (float)(BackBufferWidth - AUTOMOVER_BBOX_WIDTH);
		}
	}

	// vy += ay * dt;
	// vx += ax * dt;

	// if ( (state==AUTOMOVER_STATE_DIE) && (GetTickCount64() - die_start > AUTOMOVER_DIE_TIMEOUT) )
	// {
	// 	isDeleted = true;
	// 	return;
	// }

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CAutoMover::Render()
{
	int aniId = ID_ANI_AUTOMOVER_WALKING;
	// if (state == AUTOMOVER_STATE_DIE) 
	// {
	// 	aniId = ID_ANI_AUTOMOVER_DIE;
	// }

	CAnimations::GetInstance()->Get(aniId)->Render(x,y);
	RenderBoundingBox();
}

void CAutoMover::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		// case AUTOMOVER_STATE_DIE:
		// 	die_start = GetTickCount64();
		// 	y += (AUTOMOVER_BBOX_HEIGHT - AUTOMOVER_BBOX_HEIGHT_DIE)/2;
		// 	vx = 0;
		// 	vy = 0;
		// 	ay = 0; 
		// 	break;
		case AUTOMOVER_STATE_WALKING: 
			vx = -AUTOMOVER_WALKING_SPEED;
			break;
	}
}
