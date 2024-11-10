#include "CCamera.h"

void CCamera::UpdateFollowPlayer(float playerx, float playery)
{
	if (this->x < -100)
	{
		this->x = -100;
	}
	else if (playerx - this->x < 140)
	{
		this->x = playerx - 140;
	}
	else if (playerx - this->x > 180)
	{
		this->x = playerx - 180;
	}

	if (this->y < 160)
	{
		this->y = 160;
	}
	else if (playery - this->y > -100)
	{
		this->y = playery - (-100);
	}
	else if (playery - this->y < -140)
	{
		this->y = playery - (-140);
	}
}

int CCamera::TransitionX(float objectx)
{
	return (objectx - this->x);
}

int CCamera::TransitionY(float objecty)
{
	return -(objecty - this->y);
}
