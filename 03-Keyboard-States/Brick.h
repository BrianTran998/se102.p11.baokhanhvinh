#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "CCamera.h"

#define ID_ANI_BRICK 10000
#define BRICK_WIDTH 16

extern CCamera* camera;

class CBrick : public CGameObject {
protected:
	int w = 16;
	int h = 16;
public:
	CBrick(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
};