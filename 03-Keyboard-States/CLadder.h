#pragma once

#include "GameObject.h"

#include "Textures.h"
#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"
#include "CCamera.h"

#include "debug.h"

#define ID_TEX_TILESET 50
#define TEXTURES_DIR L"textures"

#define TEXTURE_PATH_TILESET TEXTURES_DIR "\\Tileset.png" 

//Define ANIMATION
#define ID_ANI_LADDER			50000

extern CTextures* textures;
extern CSprites* sprites;
extern CAnimations* animations;
extern CCamera* camera;

class CLadder: public CGameObject
{
protected:
	int w = 16;
	int h = 16;
public:
	CLadder() : CGameObject() {};
	CLadder(float x, float y) : CGameObject(x, y) {};
	static void LoadResource();
	void Update(DWORD dt) {};
	void Render();


	~CLadder() {}
};

