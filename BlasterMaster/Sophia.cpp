#include "Sophia.h"
#include <algorithm>
#include "debug.h"
#include "Game.h"
#include "Collision.h"

void CSophia::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (abs(vx) > abs(maxVx))
		vx = maxVx;

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount64() - untouchable_start > SOPHIA_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= SOPHIA_BBOX_WIDTH || x >= BackBufferWidth - SOPHIA_BBOX_WIDTH)
	{
		if (x <= SOPHIA_BBOX_WIDTH)
		{
			x = SOPHIA_BBOX_WIDTH;
		}
		else if (x >= BackBufferWidth - SOPHIA_BBOX_WIDTH)
		{
			x = (float)(BackBufferWidth - SOPHIA_BBOX_WIDTH);
		}
	}

	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CSophia::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	animations->Get(aniId)->Render(x, y);
}

void CSophia::SetState(int state)
{
	if (this->state == SOPHIA_STATE_DIE)
		return;
	switch (state)
	{
	case SOPHIA_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		if (isOnPlatform)
		{
			if (nx < 0) aniId = ID_ANI_SOPHIA_STATE_IDLE_LEFT;
			else aniId = ID_ANI_SOPHIA_STATE_IDLE_RIGHT;
		}
		else
		{
			if (nx < 0) aniId = ID_ANI_SOPHIA_STATE_JUMP_LEFT;
			else aniId = ID_ANI_SOPHIA_STATE_JUMP_RIGHT;
		}
		break;

	case SOPHIA_STATE_RUNNING_LEFT:
		maxVx = -SOPHIA_RUNNING_SPEED;
		ax = -SOPHIA_ACCEL_RUN_X;
		nx = -1;
		if (vx * ax < 0) aniId = ID_ANI_SOPHIA_STATE_TURNING_LEFT;
		else if (isOnPlatform) aniId = ID_ANI_SOPHIA_STATE_RUNNING_LEFT;
		else aniId = ID_ANI_SOPHIA_STATE_JUMP_LEFT;
		break;

	case SOPHIA_STATE_RUNNING_RIGHT:
		maxVx = SOPHIA_RUNNING_SPEED;
		ax = SOPHIA_ACCEL_RUN_X;
		nx = 1;
		if (vx * ax < 0) aniId = ID_ANI_SOPHIA_STATE_TURNING_RIGHT;
		else if (isOnPlatform) aniId = ID_ANI_SOPHIA_STATE_RUNNING_RIGHT;
		else aniId = ID_ANI_SOPHIA_STATE_JUMP_RIGHT;
		break;

	case SOPHIA_STATE_JUMP:
		if (isOnPlatform)
		{
			vy = -SOPHIA_JUMP_SPEED_Y;
		}
		if (nx < 0) aniId = ID_ANI_SOPHIA_STATE_JUMP_LEFT;
		else aniId = ID_ANI_SOPHIA_STATE_JUMP_RIGHT;
		break;

	case SOPHIA_STATE_RELEASE_JUMP:
		if (vy > 0)
			vy += SOPHIA_JUMP_SPEED_Y / 2;
		break;
	
	case SOPHIA_STATE_GUNUP:
		ax = 0.0f;
		vx = 0.0f;
		if (nx < 0) aniId = ID_ANI_SOPHIA_STATE_GUNUP_LEFT;
		else aniId = ID_ANI_SOPHIA_STATE_GUNUP_RIGHT;
		break;
	}

	CGameObject::SetState(state);
}

void CSophia::SetKey(int KeyCode, int KeyState)
{
	if (KeyState == -1)
	{
		this->SetState(SOPHIA_STATE_IDLE);
	}
	else
	{
		switch (this->state)
		{
		case SOPHIA_STATE_DIE:
			break;

		case SOPHIA_STATE_IDLE:
			if (KeyCode == DIK_S && KeyState == 0 && isOnPlatform) this->SetState(SOPHIA_STATE_JUMP);
			else if (KeyCode == DIK_S && KeyState == 1 && !isOnPlatform) this->SetState(SOPHIA_STATE_RELEASE_JUMP);
			if (KeyCode == DIK_LEFT) this->SetState(SOPHIA_STATE_RUNNING_LEFT);
			else if (KeyCode == DIK_RIGHT) this->SetState(SOPHIA_STATE_RUNNING_RIGHT);
			if (KeyCode == DIK_UP) this->SetState(SOPHIA_STATE_GUNUP);
			break;

		case SOPHIA_STATE_RUNNING_LEFT:
			if (KeyCode == DIK_S && KeyState == 0 && isOnPlatform) this->SetState(SOPHIA_STATE_JUMP);
			else if (KeyCode == DIK_S && KeyState == 1 && !isOnPlatform) this->SetState(SOPHIA_STATE_RELEASE_JUMP);
			if (KeyCode == DIK_LEFT) this->SetState(SOPHIA_STATE_RUNNING_LEFT);
			else if (KeyCode == DIK_RIGHT) this->SetState(SOPHIA_STATE_RUNNING_RIGHT);
			if (KeyCode == DIK_UP) this->SetState(SOPHIA_STATE_GUNUP);
			break;
		
		case SOPHIA_STATE_RUNNING_RIGHT:
			if (KeyCode == DIK_S && KeyState == 0 && isOnPlatform) this->SetState(SOPHIA_STATE_JUMP);
			else if (KeyCode == DIK_S && KeyState == 1 && !isOnPlatform) this->SetState(SOPHIA_STATE_RELEASE_JUMP);
			if (KeyCode == DIK_LEFT) this->SetState(SOPHIA_STATE_RUNNING_LEFT);
			else if (KeyCode == DIK_RIGHT) this->SetState(SOPHIA_STATE_RUNNING_RIGHT);
			if (KeyCode == DIK_UP) this->SetState(SOPHIA_STATE_GUNUP);
			break;

		case SOPHIA_STATE_JUMP:
			if (KeyCode == DIK_S && KeyState == 1 && !isOnPlatform) this->SetState(SOPHIA_STATE_RELEASE_JUMP);
			if (KeyCode == DIK_LEFT) this->SetState(SOPHIA_STATE_RUNNING_LEFT);
			else if (KeyCode == DIK_RIGHT) this->SetState(SOPHIA_STATE_RUNNING_RIGHT);
			if (KeyCode == DIK_UP) this->SetState(SOPHIA_STATE_GUNUP);
			break;

		case SOPHIA_STATE_RELEASE_JUMP:
			if (KeyCode == DIK_LEFT) this->SetState(SOPHIA_STATE_RUNNING_LEFT);
			else if (KeyCode == DIK_RIGHT) this->SetState(SOPHIA_STATE_RUNNING_RIGHT);
			if (KeyCode == DIK_UP) this->SetState(SOPHIA_STATE_GUNUP);
			break;

		case SOPHIA_STATE_GUNUP:
			if (KeyCode == DIK_S && KeyState == 0 && isOnPlatform) this->SetState(SOPHIA_STATE_JUMP);
			else if (KeyCode == DIK_S && KeyState == 1 && !isOnPlatform) this->SetState(SOPHIA_STATE_RELEASE_JUMP);
			if (KeyCode == DIK_LEFT) this->SetState(SOPHIA_STATE_RUNNING_LEFT);
			else if (KeyCode == DIK_RIGHT) this->SetState(SOPHIA_STATE_RUNNING_RIGHT);
			if (KeyCode == DIK_UP) this->SetState(SOPHIA_STATE_GUNUP);
			break;
		}
	}
}

void CSophia::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	isOnPlatform = false;
}

void CSophia::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0)
			isOnPlatform = true;
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = 0;
	}
}

void CSophia::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + SOPHIA_BBOX_WIDTH;
	bottom = top - SOPHIA_BBOX_HEIGHT;
}
