#include "CCamera.h"

CCamera::CCamera()
{
	x = y = w = h = 0;
}

CCamera::CCamera(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
}

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

	if (this->x > WORLD_WIDTH - float(w / 5 * 4))
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

void CCamera::Transition(float &objectx, float &objecty)
{
	objectx = objectx - this->x;
	objecty = -(objecty - this->y);
}

bool CCamera::isLocationInCamera(float x, float y)
{
	if (x >= this->x &&
		x <= this->x + this->w &&
		y <= this->y &&
		y >= this->y - this->h)
	{
		return true;
	}
	else return false;
}
