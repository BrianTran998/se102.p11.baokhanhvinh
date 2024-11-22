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

bool CCamera::isObjectInCamera(float objectx, float objecty, float objectw, float objecth)
{
	if (
		(	//Object left x or object right x is inside camera
			(objectx >= this->x &&
			objectx <= this->x + this->w) ||
			(objectx+objectw >=this->x &&
			objectx+objectw <= this->x+this->w)
		)
		&&
		(	//Object top y or object bottom y is inside camera
			(objecty <= this->y &&
			objecty >= this->y - this->h) ||
			(objecty-objecth <= this->y &&
			objecty-objecth >= this->y-this->h)
		)
	   )
	{
		return true;
	}
	else return false;
}

bool CCamera::isInSceneNode(float scenex, float sceney, float scenew, float sceneh)
{
	//Case camera is contained in scene node
	if (
		(	//Camera x left or right is inside scene node
			(this->x >= scenex &&
				this->x <= scenex + scenew) ||
			(this->x + this->w >= scenex &&
				this->x + this->w <= scenex + scenew)
		)
		&&
		(	//Camera y top or bottom is inside scene node
			(this->y <= sceney &&
				this->y >= sceney - sceneh) ||
			(this->y - this->h <= sceney &&
				this->y - this->h >= sceney - sceneh)
		)
	   )
	{
		return true;
	}
	else return false;
}
