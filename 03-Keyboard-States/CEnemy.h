#pragma once
#include "GameObject.h"

#include "Textures.h"
#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"
#include "CCamera.h"

#define ID_TEX_ENEMY 40
#define TEXTURES_DIR L"textures"

#define TEXTURE_PATH_ENEMY TEXTURES_DIR "\\Enemies.png" 

class CEnemy : public CGameObject
{
public:
	CEnemy() : CGameObject() {};
	CEnemy(float x, float y) : CGameObject(x, y) {};
	virtual void LoadResource() = 0;

	~CEnemy() {}
};
