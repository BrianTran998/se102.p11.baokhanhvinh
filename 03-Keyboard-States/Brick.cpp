#include "Brick.h"

void CBrick::Render()
{
	CAnimations *animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BRICK + this->step)->Render(x, y);
}