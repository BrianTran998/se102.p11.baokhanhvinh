#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define JASON_WALKING_SPEED		0.1f

#define JASON_ACCEL_WALK_X	0.001f

#define JASON_GRAVITY			0.002f

#define JASON_STATE_IDLE			10000
#define JASON_STATE_WALKING_RIGHT	10100
#define JASON_STATE_WALKING_LEFT	10200


#pragma region ANIMATION_ID

#define ID_ANI_JASON_IDLE_RIGHT 10400
#define ID_ANI_JASON_IDLE_LEFT 10401

#define ID_ANI_JASON_WALKING_RIGHT 10500
#define ID_ANI_JASON_WALKING_LEFT 10501

#pragma endregion




#define GROUND_Y 160.0f

class CJason : public CGameObject
{
	float maxVx;
	float ax;				// acceleration on x 
public:
	CJason(float x, float y) : CGameObject(x, y)
	{
		maxVx = 0.0f;
		ax = 0.0f;
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};