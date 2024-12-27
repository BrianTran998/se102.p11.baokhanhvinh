#include "Walker.h"
#include <algorithm>
#include "debug.h"
#include "Game.h"
#include "Collision.h"

void CWalker::SetState(int state)
{
	switch (state)
	{
	case WALKER_STATE_IDLE:
		vx = 0;
		if (nx < 0) aniId = ID_ANI_WALKER_IDLE_LEFT;
		else aniId = ID_ANI_WALKER_IDLE_RIGHT;
		break;
	case WALKER_STATE_WALKING_LEFT:
		nx = -1;
		vx = -WALKER_WALKING_SPEED;
		aniId = ID_ANI_WALKER_WALKING_LEFT;
		break;
	case WALKER_STATE_WALKING_RIGHT:
		nx = 1;
		vx = WALKER_WALKING_SPEED;
		aniId = ID_ANI_WALKER_WALKING_RIGHT;
		break;
	case WALKER_STATE_JUMP:
		vy = WALKER_JUMP_SPEED_Y;
		break;
	}
}

void CWalker::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	isOnPlatform = false;
}

void CWalker::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0)
			isOnPlatform = true;
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		if (this->state == WALKER_STATE_WALKING_LEFT)
		{
			this->SetState(WALKER_STATE_WALKING_RIGHT);
		}
		else this->SetState(WALKER_STATE_WALKING_LEFT);
	}
}

void CWalker::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - WALKER_BBOX_WIDTH / 2;
	top = y - WALKER_BBOX_HEIGHT / 2;
	right = left + WALKER_BBOX_WIDTH;
	bottom = top + WALKER_BBOX_HEIGHT;
}

void CWalker::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (abs(vx) > abs(maxVx))
		vx = maxVx;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= WALKER_BBOX_WIDTH || x >= BackBufferWidth - WALKER_BBOX_WIDTH)
	{
		if (x <= WALKER_BBOX_WIDTH)
		{
			x = WALKER_BBOX_WIDTH;
		}
		// Temp hard code for world width is 1725
		else if (x >= 1725)
		{
			x = 1725;
		}
	}

	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CWalker::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	animations->Get(aniId)->Render(x, y);
}
