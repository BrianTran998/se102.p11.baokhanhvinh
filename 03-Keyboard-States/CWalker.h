#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define WALKER_WALKING_SPEED		0.05f
#define WALKER_ACCEL_WALK_X			0.0005f
#define WALKER_JUMP_SPEED_Y			0.3f
#define WALKER_GRAVITY				0.002f
#define WALKER_JUMP_DEFLECT_SPEED	0.4f

//Define STATE

#define WALKER_STATE_IDLE			401
#define WALKER_STATE_WALKING_LEFT	402
#define WALKER_STATE_WALKING_RIGHT	403
#define WALKER_STATE_JUMP			404
#define WALKER_STATE_DIE			-400

//Define ANIMATION

#define ID_ANI_WALKER_IDLE_LEFT			40001
#define ID_ANI_WALKER_IDLE_RIGHT		40002
#define ID_ANI_WALKER_WALKING_LEFT		40003
#define ID_ANI_WALKER_WALKING_RIGHT		40004

class CWalker : public CGameObject
{
protected:
	int w = 20;
	int h = 50;
public:
	CWalker(float x, float y) : CGameObject(x, y)
	{
		maxVx = 0.0f;
		ax = 0.0f;
		ay = WALKER_GRAVITY;

		isOnPlatform = false;
	}

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);

	static void LoadResource();
	
	void SetState(int state = WALKER_STATE_IDLE);
	
	void Update(DWORD dt);
	
	void Render();
	
	~CWalker() {}
};

