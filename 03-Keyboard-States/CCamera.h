#pragma once
#include "GameObject.h"
#include "Common.h"

class CCamera
{
protected:
	float x = 0;
	float y = 0;
	int w = 0;
	int h = 0;
public:
	CCamera();
	CCamera(float x, float y, int width, int height);
	void UpdateFollowPlayer(float playerx, float playery);
	void Transition(float& objectx, float& objecty);
	~CCamera() {}
};

