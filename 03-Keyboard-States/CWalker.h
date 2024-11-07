#pragma once
#include "CEnemy.h"

#include "Textures.h"
#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "debug.h"

#define WALKER_SMALL_START_X	150.0f
#define WALKER_SMALL_START_Y	10.0f

#define WALKER_WALKING_SPEED		0.05f
#define WALKER_JUMP_SPEED_Y			0.3f
#define WALKER_GRAVITY				0.002f

//Define STATE

#define WALKER_STATE_IDLE			401
#define WALKER_STATE_WALKING_LEFT	402
#define WALKER_STATE_WALKING_RIGHT	403
#define WALKER_STATE_JUMP			404

//Define ANIMATION

#define ID_ANI_WALKER_IDLE_LEFT			40001
#define ID_ANI_WALKER_IDLE_RIGHT		40002
#define ID_ANI_WALKER_WALKING_LEFT		40003
#define ID_ANI_WALKER_WALKING_RIGHT		40004

extern CTextures* textures;
extern CSprites* sprites;
extern CAnimations* animations;

class CWalker: public CEnemy
{
protected:
public:
	CWalker() : CEnemy() {};
	CWalker(float x, float y) : CEnemy(x, y) {};

	void LoadResource();
	
	void SetState(int state = WALKER_STATE_IDLE);
	
	void Update(DWORD dt);
	
	void Render();
	
	~CWalker() {}
};

