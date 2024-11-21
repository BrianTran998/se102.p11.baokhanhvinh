#pragma once
#include "CPlayer.h"

#include "Textures.h"
#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "debug.h"

#define JASON_SMALL_WALKING_SPEED			0.1f
#define JASON_SMALL_CRAWLING_SPEED			0.05f
#define JASON_SMALL_SWIMMING_SPEED			0.08f
#define JASON_SMALL_CLIMBING_SPEED			0.1f
#define JASON_SMALL_CLIMBING_SIDE_SPEED		0.05f

#define JASON_SMALL_JUMP_SPEED_Y				0.5f
#define JASON_SMALL_SWIMMING_UP_SPEED_Y			0.1f
#define JASON_SMALL_SWIMMING_DOWN_SPEED_Y		0.1f

#define JASON_SMALL_GRAVITY			0.002f
#define JASON_SMALL_GRAVITY_SWIM	0.002f

//Define STATE
#define JASON_SMALL_STATE_IDLE				301
#define JASON_SMALL_STATE_WALKING_LEFT		302
#define JASON_SMALL_STATE_WALKING_RIGHT		303

#define JASON_SMALL_STATE_CRAWL				304
#define JASON_SMALL_STATE_CRAWLING_LEFT		306
#define JASON_SMALL_STATE_CRAWLING_RIGHT	307
#define JASON_SMALL_STATE_CRALW_RELEASE		308

#define JASON_SMALL_STATE_JUMP					310
#define JASON_SMALL_STATE_RELEASE_JUMP			312

#define JASON_SMALL_STATE_CLIMB_UP			314
#define JASON_SMALL_STATE_CLIMB_DOWN		315
#define JASON_SMALL_STATE_CLIMB				316
#define JASON_SMALL_STATE_CLIMB_LEFT		317
#define JASON_SMALL_STATE_CLIMB_RIGHT		318

#define JASON_SMALL_STATE_SWIM_LEFT				320
#define JASON_SMALL_STATE_SWIM_RIGHT			321
#define JASON_SMALL_STATE_SWIM_UP				322
#define JASON_SMALL_STATE_SWIM_UP_RELEASE		323
#define JASON_SMALL_STATE_SWIM_DOWN				324
#define JASON_SMALL_STATE_SWIM_RELEASE			325
#define JASON_SMALL_STATE_SWIM_ENTER			326

#define JASON_SMALL_STATE_DEAD				327
#define JASON_SMALL_STATE_FINISH_DEAD		328

//Define ANIMATION
#define ID_ANI_JASON_SMALL_IDLE_LEFT			30000
#define ID_ANI_JASON_SMALL_IDLE_RIGHT			30001
#define ID_ANI_JASON_SMALL_WALKING_LEFT			30002
#define ID_ANI_JASON_SMALL_WALKING_RIGHT		30003

#define ID_ANI_JASON_SMALL_CRAWL_IDLE_LEFT			30004
#define ID_ANI_JASON_SMALL_CRAWL_IDLE_RIGHT			30005
#define ID_ANI_JASON_SMALL_CRAWLING_LEFT			30006
#define ID_ANI_JASON_SMALL_CRAWLING_RIGHT			30007
#define ID_ANI_JASON_SMALL_CRALW_RELEASE_LEFT		30008
#define ID_ANI_JASON_SMALL_CRALW_RELEASE_RIGHT		30009

#define ID_ANI_JASON_SMALL_JUMP_LEFT				30010
#define ID_ANI_JASON_SMALL_JUMP_RIGHT				30011

#define ID_ANI_JASON_SMALL_CLIMB_UP		30014
#define ID_ANI_JASON_SMALL_CLIMB_DOWN	30015
#define ID_ANI_JASON_SMALL_CLIMB_IDLE	30016

#define ID_ANI_JASON_SMALL_SWIM_LEFT	30017
#define ID_ANI_JASON_SMALL_SWIM_RIGHT	30018

#define ID_ANI_JASON_SMALL_DEAD					30019
#define ID_ANI_JASON_SMALL_FINISH_DEAD			30020


extern CTextures* textures;
extern CSprites* sprites;
extern CAnimations* animations;
extern CCamera* camera;

class CJasonSmall: public CPlayer 
{
protected:
	int isJumping = 0;
	int isCrawling = 0;
	int isClimbing = 0;
	int isSwimming = 0;
	int isClimbable = 0;
	int isDead = 0;
	int countTimeDead = 0;
public:
	CJasonSmall() : CPlayer() {};
	CJasonSmall(float x, float y) : CPlayer(x, y) {};

	static void LoadResource();

	void SetState(int state = JASON_SMALL_STATE_IDLE);

	void SetKey(int KeyCode = DIK_LEFT, int KeyState = -1);

	void Update(DWORD dt);

	void Render();

	~CJasonSmall() {}
};

