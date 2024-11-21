#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

bool CGameObject::isInSceneNode(float scenex, float sceney, float scenew, float sceneh)
{
	float objectTopLeftX = this->x;
	float objectTopLeftY = this->y;
	float objectTopRightX = this->x + this->width;
	float objectTopRightY = this->y;
	float objectBottomLeftX = this->x;
	float objectBottomLeftY = this->y - this->height;
	float objectBottomRightX = this->x + this->width;
	float objectBottomRightY = this->y - this->height;

	//Case object is contained in scene node
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
	//Case object is not contained in scene node, but still crosses it
	//Insert code here

	return false;

}

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;	
	state = -1;
}