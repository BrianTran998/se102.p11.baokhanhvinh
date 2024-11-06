#pragma once
#include "GameObject.h"

#include "Textures.h"
#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

class CPlayer: public CGameObject
{
public:
	CPlayer() : CGameObject() {};
	CPlayer(float x, float y) : CGameObject(x, y) {};
	virtual void SetKey(int KeyCode, int KeyState) = 0;
	virtual void LoadResource() = 0;


	~CPlayer() {}
};

