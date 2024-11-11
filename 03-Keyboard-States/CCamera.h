#pragma once
#include "GameObject.h"

class CCamera: public CGameObject
{
protected:
	int w = 320;
	int h = 240;
public:
	CCamera() : CGameObject() {};
	CCamera(float x, float y) : CGameObject(x, y) {};
	void UpdateFollowPlayer(float playerx, float playery);
	float TransitionX(float objectx);
	float TransitionY(float objecty);
	void Update(DWORD dt) {};
	void Render() {};
	~CCamera() {}
};

