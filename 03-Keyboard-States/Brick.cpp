#include "Brick.h"

void CBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	float drawx = camera->TransitionX(x);
	float drawy = camera->TransitionY(y);
	if (((drawx < -30) || (drawx > 320)) &&
		((drawy < -50) || (drawy > 240)))
	{
		return;
	}
	else animations->Get(ID_ANI_BRICK)->Render(drawx, drawy);
}