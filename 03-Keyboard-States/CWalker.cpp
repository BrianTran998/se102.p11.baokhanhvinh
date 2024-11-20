#include "CWalker.h"

void CWalker::LoadResource()
{
	textures->Add(ID_TEX_ENEMY, TEXTURE_PATH_ENEMY);
	LPTEXTURE textWalker = textures->Get(ID_TEX_ENEMY);

	LPANIMATION ani;

	//Walker walk left
	sprites->Add(4000001, 91, 2, 103, 26, textWalker);
	sprites->Add(4000002, 108, 1, 121, 26, textWalker);

	ani = new CAnimation(100);
	ani->Add(4000001);
	ani->Add(4000002);
	animations->Add(ID_ANI_WALKER_WALKING_LEFT, ani);

	//Walker idle left
	ani = new CAnimation(100);
	ani->Add(4000001);
	animations->Add(ID_ANI_WALKER_IDLE_LEFT, ani);


	//Walker walk right
	sprites->Add(4000003, 103, 2, 91, 26, textWalker, -1);
	sprites->Add(4000004, 121, 1, 108, 26, textWalker, -1);

	ani = new CAnimation(100);
	ani->Add(4000003);
	ani->Add(4000004);
	animations->Add(ID_ANI_WALKER_WALKING_RIGHT, ani);

	//Walker idle right
	ani = new CAnimation(100);
	ani->Add(4000003);
	animations->Add(ID_ANI_WALKER_IDLE_RIGHT, ani);
}

void CWalker::SetState(int state)
{
	switch (state)
	{
	case WALKER_STATE_IDLE:
		vx = 0;
		break;
	case WALKER_STATE_WALKING_LEFT:
		nx = -1;
		vx = -WALKER_WALKING_SPEED;
		break;
	case WALKER_STATE_WALKING_RIGHT:
		nx = 1;
		vx = WALKER_WALKING_SPEED;
		break;
	case WALKER_STATE_JUMP:
		vy = WALKER_JUMP_SPEED_Y;
		break;
	}
}

void CWalker::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	vy -= WALKER_GRAVITY * dt;

	if (vx == 0) SetState(WALKER_STATE_WALKING_LEFT);

	// simple screen edge collision!!!
	if (vx > 0 && x > WORLD_WIDTH)
	{
		x = WORLD_WIDTH;
		SetState(WALKER_STATE_WALKING_LEFT);
	}
	if (vx < 0 && x < 0)
	{
		x = 0;
		SetState(WALKER_STATE_WALKING_RIGHT);
	}
	if (y <= 160.f)
	{
		vy = 0;
		y = 160.0f;
	}
}

void CWalker::Render()
{
	int ani = ID_ANI_WALKER_IDLE_LEFT;
	if (nx < 0)
	{
		if (vx != 0) ani = ID_ANI_WALKER_WALKING_LEFT;
		else ani = ID_ANI_WALKER_IDLE_LEFT;
	}
	else if (nx > 0)
	{
		if (vx != 0) ani = ID_ANI_WALKER_WALKING_RIGHT;
		else ani = ID_ANI_WALKER_IDLE_RIGHT;
	}
	DebugOutTitle(L"y = %0.5f", float(y));
	animations->Get(ani)->Render(x, y);
}



