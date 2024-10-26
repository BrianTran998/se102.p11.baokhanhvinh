#include "Fbird.h"
#include "Game.h"


Fbird::Fbird(float x, float y, float vx) :CGameObject(x, y)
{
	this->vx = vx;
};

void Fbird::Update(DWORD dt)
{
	x += vx * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - 14) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - FBIRD_WIDTH)
		{
			x = (float)(BackBufferWidth - FBIRD_WIDTH);
		}
	}
}

void Fbird::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	if (vx > 0) ani = CAnimations::GetInstance()->Get(410);
	else ani = CAnimations::GetInstance()->Get(411);

	ani->Render(x, y);
}
