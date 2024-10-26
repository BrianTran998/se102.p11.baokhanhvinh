#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define FBIRD_WIDTH 14

class Fbird : public CGameObject
{
protected:
	float vx;
public:
	Fbird(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
};


