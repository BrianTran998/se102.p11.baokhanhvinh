#pragma once
#include "GameObject.h"

#include "Textures.h"
#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"
#include "CCamera.h"

#define ID_TEX_PLAYER 30
#define TEXTURES_DIR L"textures"

#define TEXTURE_PATH_PLAYER TEXTURES_DIR "\\Jason.png" 

class CPlayer: public CGameObject
{
public:
	CPlayer() : CGameObject() {};
	CPlayer(float x, float y) : CGameObject(x, y) {};
	virtual void SetKey(int KeyCode, int KeyState) = 0;


	~CPlayer() {}
};

