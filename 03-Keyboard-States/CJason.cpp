#include "CJason.h"

void CJason::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	// simple fall down
	vy += JASON_GRAVITY * dt;

	vx += ax * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx;

	DebugOutTitle(L"vx = %0.5f", this->vx);


	// BAD & sinful platform collision handling, see next sample for correct collision handling
	if (y > GROUND_Y)
	{
		vy = 0; y = GROUND_Y;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void CJason::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

		if (vx == 0)
		{
			if (nx > 0) aniId = ID_ANI_JASON_IDLE_RIGHT;
			else aniId = ID_ANI_JASON_IDLE_LEFT;
		}
		else if (vx > 0)
		{
			aniId = ID_ANI_JASON_WALKING_RIGHT;
		}
		else // vx < 0
		{
			aniId = ID_ANI_JASON_WALKING_LEFT;
		}

	if (aniId == -1) aniId = ID_ANI_JASON_IDLE_RIGHT;

	animations->Get(aniId)->Render(x, y);
}

void CJason::SetState(int state)
{
	switch (state)
	{
	case JASON_STATE_WALKING_RIGHT:
		maxVx = JASON_WALKING_SPEED;
		ax = JASON_ACCEL_WALK_X;
		nx = 1;
		break;
	case JASON_STATE_WALKING_LEFT:
		maxVx = -JASON_WALKING_SPEED;
		ax = -JASON_ACCEL_WALK_X;
		nx = -1;
		break;
	case JASON_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;
	}

	CGameObject::SetState(state);
}

