#include "CCamera.h"

void CCamera::UpdateFollowPlayer(float playerx, float playery)
{
	if (this->x < float(-(w / 5)))
	{
		//Do nothing
	}
	else if (playerx - this->x < 140)
	{
		this->x = playerx - 140;
	}

	if (this->x > 450.0f - float(w / 5 * 4))
	{
		//Do nothing
	}
	else if (playerx - this->x > 180)
	{
		this->x = playerx - 180;
	}

	if (this->y < 160)
	{
		//Do nothing
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

float CCamera::TransitionX(float objectx)
{
	return (objectx - this->x);
}

float CCamera::TransitionY(float objecty)
{
	return -(objecty - this->y);
}
