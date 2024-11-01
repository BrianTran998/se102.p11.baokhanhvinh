#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BRICK 10000
#define BRICK_WIDTH 6

class CBrick : public CGameObject
{
private:
	int step = 0;

public:
	CBrick(float x, float y, int step) : CGameObject(x, y)
	{
		this->step = step;
	}
	void Render();
	void Update(DWORD dt) {}
};