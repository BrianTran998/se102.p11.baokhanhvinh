#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include <dinput.h>

#define SOPHIA_RUNNING_SPEED 0.2f

#define SOPHIA_ACCEL_RUN_X 0.0007f

#define SOPHIA_JUMP_SPEED_Y 0.6f

#define SOPHIA_GRAVITY 0.002f

#define SOPHIA_JUMP_DEFLECT_SPEED 0.4f

#define SOPHIA_STATE_DIE -300
#define SOPHIA_STATE_IDLE 300

#define SOPHIA_STATE_RUNNING_LEFT 302
#define SOPHIA_STATE_RUNNING_RIGHT 303

#define SOPHIA_STATE_JUMP 306
#define SOPHIA_STATE_RELEASE_JUMP 307

#define SOPHIA_STATE_GUNUP 308

#pragma region ANIMATION_ID

#define ID_ANI_SOPHIA_STATE_DIE 39999
#define ID_ANI_SOPHIA_STATE_IDLE_LEFT 30001
#define ID_ANI_SOPHIA_STATE_IDLE_RIGHT 30002

#define ID_ANI_SOPHIA_STATE_RUNNING_LEFT 30003
#define ID_ANI_SOPHIA_STATE_RUNNING_RIGHT 30004

#define ID_ANI_SOPHIA_STATE_TURNING_LEFT 30005
#define ID_ANI_SOPHIA_STATE_TURNING_RIGHT 30006

#define ID_ANI_SOPHIA_STATE_JUMP_LEFT 30007
#define ID_ANI_SOPHIA_STATE_JUMP_RIGHT 30008

#define ID_ANI_SOPHIA_STATE_GUNUP_LEFT 30009
#define ID_ANI_SOPHIA_STATE_GUNUP_RIGHT 30010

#pragma endregion

#define SOPHIA_BBOX_WIDTH 25
#define SOPHIA_BBOX_HEIGHT 17

#define SOPHIA_UNTOUCHABLE_TIME 2500

class CSophia : public CGameObject
{
	float maxVx;
	float ax; // acceleration on x
	float ay; // acceleration on y
	int aniId = ID_ANI_SOPHIA_STATE_IDLE_RIGHT;

	int untouchable;
	ULONGLONG untouchable_start;
	BOOLEAN isOnPlatform;

public:
	CSophia(float x, float y) : CGameObject(x, y)
	{
		maxVx = SOPHIA_RUNNING_SPEED;
		ax = 0.0f;
		ay = SOPHIA_GRAVITY;

		untouchable = 0;
		untouchable_start = -1;
		isOnPlatform = false;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	void Render();
	void SetState(int state);

	void SetKey(int KeyCode = DIK_LEFT, int KeyState = -1);

	int IsCollidable()
	{
		return (state != SOPHIA_STATE_DIE);
	}

	int IsBlocking() { return (state != SOPHIA_STATE_DIE && untouchable == 0); }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void StartUntouchable()
	{
		untouchable = 1;
		untouchable_start = GetTickCount64();
	}

	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};