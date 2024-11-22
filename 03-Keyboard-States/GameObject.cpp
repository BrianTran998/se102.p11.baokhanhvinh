#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

bool CGameObject::isInSceneNode(float scenex, float sceney, float scenew, float sceneh)
{
	//Case object is contained in scene node
	if (
		(	//Object x left or right is inside scene node
			(this->x >= scenex &&
				this->x <= scenex + scenew) ||
			(this->x + this->w >= scenex &&
				this->x + this->w <= scenex + scenew)
			)
		&&
		(	//Object y top or bottom is inside scene node
			(this->y <= sceney &&
				this->y >= sceney - sceneh) ||
			(this->y - this->h <= sceney &&
				this->y - this->h >= sceney - sceneh)
		)
	   )
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