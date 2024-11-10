#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BRICK 10000
#define ID_ANI_BACKGROUND 9000
#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

class CBrick : public CGameObject
{
	int aniId = ID_ANI_BRICK;

public:
	CBrick(float x, float y, int isBackground = 0) : CGameObject(x, y)
	{
		this->aniId = (isBackground == 1 ? ID_ANI_BACKGROUND : ID_ANI_BRICK);
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float &l, float &t, float &r, float &b);
};