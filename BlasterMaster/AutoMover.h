#pragma once
#include "GameObject.h"

#define AUTOMOVER_GRAVITY 0.002f
#define AUTOMOVER_WALKING_SPEED 0.05f


#define AUTOMOVER_BBOX_WIDTH 16
#define AUTOMOVER_BBOX_HEIGHT 14
#define AUTOMOVER_BBOX_HEIGHT_DIE 7

#define AUTOMOVER_DIE_TIMEOUT 500

#define AUTOMOVER_STATE_WALKING 100
#define AUTOMOVER_STATE_DIE 200

#define ID_ANI_AUTOMOVER_WALKING 5000
#define ID_ANI_AUTOMOVER_DIE 5001

class CAutoMover : public CGameObject
{
protected:
	float ax;				
	float ay; 

	ULONGLONG die_start;

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	// virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public: 	
	CAutoMover(float x, float y);
	virtual void SetState(int state);
};