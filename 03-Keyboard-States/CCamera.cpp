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

bool CCamera::isLocationInCamera(float objectx, float objecty)
{
	if (objectx >= this->x &&
		objectx <= this->x + this->w &&
		objecty <= this->y &&
		objecty >= this->y - this->h)
	{
		return true;
	}
	else return false;
}

bool CCamera::isInSceneNode(float scenex, float sceney, float scenew, float sceneh)
{
	float objectTopLeftX = this->x;
	float objectTopLeftY = this->y;
	float objectTopRightX = this->x + this->w;
	float objectTopRightY = this->y;
	float objectBottomLeftX = this->x;
	float objectBottomLeftY = this->y - this->h;
	float objectBottomRightX = this->x + this->w;
	float objectBottomRightY = this->y - this->h;

	//Case camera is contained in scene node
	if (objectTopLeftX >= scenex &&
		objectTopLeftX <= scenex + scenew &&
		objectTopLeftY <= sceney &&
		objectTopLeftY >= sceney - sceneh)
	{
		return true;
	}

	if (objectTopRightX >= scenex &&
		objectTopRightX <= scenex + scenew &&
		objectTopRightY <= sceney &&
		objectTopRightY >= sceney - sceneh)
	{
		return true;
	}

	if (objectBottomLeftX >= scenex &&
		objectBottomLeftX <= scenex + scenew &&
		objectBottomLeftY <= sceney &&
		objectBottomLeftY >= sceney - sceneh)
	{
		return true;
	}

	if (objectBottomRightX >= scenex &&
		objectBottomRightX <= scenex + scenew &&
		objectBottomRightY <= sceney &&
		objectBottomRightY >= sceney - sceneh)
	{
		return true;
	}

	return false;
}
