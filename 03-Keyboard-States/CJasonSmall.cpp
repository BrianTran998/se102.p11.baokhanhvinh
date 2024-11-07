#include "CJasonSmall.h"

void CJasonSmall::LoadResource()
{
	textures->Add(ID_TEX_JASON_SMALL, TEXTURE_PATH_JASON_SMALL);

	LPTEXTURE textJasonSmall = textures->Get(ID_TEX_JASON_SMALL);

	LPANIMATION ani;

	//Jason small idle left
	sprites->Add(30001, 3, 30, 10, 45, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(30001);
	animations->Add(ID_ANI_JASON_SMALL_IDLE_LEFT, ani);

	//Jason small idle right
	sprites->Add(30002, 3, 45, 10, 30, textJasonSmall, -1);

	ani = new CAnimation(100);
	ani->Add(30002);
	animations->Add(ID_ANI_JASON_SMALL_IDLE_RIGHT, ani);

	//Jason small walk left
	sprites->Add(30003, 12, 30, 19, 45, textJasonSmall);
	sprites->Add(30004, 21, 30, 28, 45, textJasonSmall);
	sprites->Add(30005, 30, 30, 37, 45, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(30003);
	ani->Add(30004);
	ani->Add(30005);
	ani->Add(30004);
	animations->Add(ID_ANI_JASON_SMALL_WALKING_LEFT, ani);

	//Jason small walk right
	sprites->Add(30006, 12, 45, 19, 30, textJasonSmall, -1);
	sprites->Add(30007, 21, 45, 28, 30, textJasonSmall, -1);
	sprites->Add(30008, 30, 45, 37, 30, textJasonSmall, -1);

	ani = new CAnimation(100);
	ani->Add(30006);
	ani->Add(30007);
	ani->Add(30008);
	ani->Add(30007);
	animations->Add(ID_ANI_JASON_SMALL_WALKING_RIGHT, ani);

	//Jason small crawl left
	sprites->Add(30009, 3, 47, 18, 54, textJasonSmall);
	sprites->Add(30010, 20, 47, 35, 54, textJasonSmall);

	ani = new CAnimation(120);
	ani->Add(30009);
	animations->Add(ID_ANI_JASON_SMALL_CRAWL_IDLE_LEFT, ani);

	ani = new CAnimation(120);
	ani->Add(30009);
	ani->Add(30010);
	animations->Add(ID_ANI_JASON_SMALL_CRAWLING_LEFT, ani);

	//Jason small crawl right
	sprites->Add(30011, 3, 54, 18, 47, textJasonSmall, -1);
	sprites->Add(30012, 20, 54, 35, 47, textJasonSmall, -1);

	ani = new CAnimation(120);
	ani->Add(30011);
	animations->Add(ID_ANI_JASON_SMALL_CRAWL_IDLE_RIGHT, ani);

	ani = new CAnimation(120);
	ani->Add(30011);
	ani->Add(30012);
	animations->Add(ID_ANI_JASON_SMALL_CRAWLING_RIGHT, ani);

	//Jason small jump left
	ani = new CAnimation(100);
	ani->Add(30003);
	animations->Add(ID_ANI_JASON_SMALL_JUMP_LEFT, ani);

	//Jason small jump right
	ani = new CAnimation(100);
	ani->Add(30006);
	animations->Add(ID_ANI_JASON_SMALL_JUMP_RIGHT, ani);

	//Jason small climb ladder
	sprites->Add(30013, 40, 47, 49, 62, textJasonSmall);
	sprites->Add(30014, 57, 47, 66, 62, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(30013);
	animations->Add(ID_ANI_JASON_SMALL_CLIMB_IDLE, ani);

	ani = new CAnimation(100);
	ani->Add(30013);
	ani->Add(30014);
	animations->Add(ID_ANI_JASON_SMALL_CLIMB_UP, ani);

	ani = new CAnimation(100);
	ani->Add(30014);
	ani->Add(30013);
	animations->Add(ID_ANI_JASON_SMALL_CLIMB_DOWN, ani);

	//Jason small swim left
	sprites->Add(30015, 39, 36, 53, 45, textJasonSmall);
	sprites->Add(30016, 56, 36, 70, 45, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(30015);
	ani->Add(30016);
	animations->Add(ID_ANI_JASON_SMALL_SWIM_LEFT, ani);

	//Jason small swim right
	sprites->Add(30017, 39, 45, 53, 36, textJasonSmall, -1);
	sprites->Add(30018, 56, 45, 70, 36, textJasonSmall, -1);

	ani = new CAnimation(100);
	ani->Add(30017);
	ani->Add(30018);
	animations->Add(ID_ANI_JASON_SMALL_SWIM_RIGHT, ani);

	//Jason small dead
	sprites->Add(30019, 3, 64, 18, 79, textJasonSmall);
	sprites->Add(30020, 20, 64, 35, 79, textJasonSmall);
	sprites->Add(30021, 37, 64, 52, 79, textJasonSmall);
	sprites->Add(30022, 54, 64, 69, 79, textJasonSmall);
	sprites->Add(30023, 3, 81, 18, 96, textJasonSmall);
	sprites->Add(30024, 20, 89, 35, 96, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(30019);
	ani->Add(30020);
	ani->Add(30021);
	ani->Add(30022);
	ani->Add(30023);
	ani->Add(30024);
	animations->Add(ID_ANI_JASON_SMALL_DEAD, ani);

	//Jason big turn down
	sprites->Add(30017, 208, 3, 231, 34, textJasonSmall);
	sprites->Add(30018, 233, 3, 256, 34, textJasonSmall);
	sprites->Add(30019, 258, 3, 281, 34, textJasonSmall);

	//Jason big turn up
	sprites->Add(30020, 208, 36, 231, 67, textJasonSmall);
	sprites->Add(30021, 233, 36, 256, 67, textJasonSmall);
	sprites->Add(30022, 258, 36, 281, 67, textJasonSmall);

	//Jason big turn left
	sprites->Add(30023, 208, 69, 231, 100, textJasonSmall);
	sprites->Add(30024, 233, 69, 256, 100, textJasonSmall);
	sprites->Add(30025, 258, 69, 281, 100, textJasonSmall);

	//Jason big dead
	sprites->Add(30026, 283, 3, 306, 34, textJasonSmall);
	sprites->Add(30027, 308, 3, 331, 34, textJasonSmall);
	sprites->Add(30028, 333, 3, 356, 34, textJasonSmall);
	sprites->Add(30029, 358, 3, 381, 34, textJasonSmall);
	sprites->Add(30030, 383, 19, 406, 34, textJasonSmall);
}

void CJasonSmall::SetState(int state)
{
	if (this->state == ID_ANI_JASON_SMALL_DEAD)
	{
		return;
	}
	else switch (state)
	{
	//IDLE
	case JASON_SMALL_STATE_IDLE:
		vx = 0;
		break;
	//WALK
	case JASON_SMALL_STATE_WALKING_LEFT:
		isClimbing = 0;
		nx = -1;
		vx = -JASON_SMALL_WALKING_SPEED;
		break;
	case JASON_SMALL_STATE_WALKING_RIGHT:
		isClimbing = 0;
		nx = 1;
		vx = JASON_SMALL_WALKING_SPEED;
		break;
	//CRAWL
	case JASON_SMALL_STATE_CRAWL:
		isCrawling = 1;
		break;
	case JASON_SMALL_STATE_CRAWLING_LEFT:
		nx = -1;
		vx = -JASON_SMALL_CRAWLING_SPEED;
		break;
	case JASON_SMALL_STATE_CRAWLING_RIGHT:
		nx = 1;
		vx = JASON_SMALL_CRAWLING_SPEED;
		break;
	case JASON_SMALL_STATE_CRALW_RELEASE:
		isCrawling = 0;
		break;
	//JUMP
	case JASON_SMALL_STATE_JUMP:
		isClimbing = 0;
		vy = -JASON_SMALL_JUMP_SPEED_Y;
		break;
	case JASON_SMALL_STATE_RELEASE_JUMP:
		if (vy < 0) vy += JASON_SMALL_JUMP_SPEED_Y / 2;
		break;
	//CLIMB
	case JASON_SMALL_STATE_CLIMB:
		isClimbing = 1;
		isCrawling = 0;
		isJumping = 0;
		vy = 0;
		break;
	case JASON_SMALL_STATE_CLIMB_UP:
		vy = -JASON_SMALL_CLIMBING_SPEED;
		break;
	case JASON_SMALL_STATE_CLIMB_DOWN:
		vy = JASON_SMALL_CLIMBING_SPEED;
		break;
	case JASON_SMALL_STATE_CLIMB_LEFT:
		vx = -JASON_SMALL_CLIMBING_SIDE_SPEED;
		break;
	case JASON_SMALL_STATE_CLIMB_RIGHT:
		vx = JASON_SMALL_CLIMBING_SIDE_SPEED;
		break;

	//SWIM
	case JASON_SMALL_STATE_SWIM_LEFT:
		nx = -1;
		vx = -JASON_SMALL_SWIMMING_SPEED;
		break;
	case JASON_SMALL_STATE_SWIM_RIGHT:
		nx = 1;
		vx = JASON_SMALL_SWIMMING_SPEED;
		break;
	case JASON_SMALL_STATE_SWIM_UP:
		vy = -JASON_SMALL_SWIMMING_UP_SPEED_Y;
		break;
	case JASON_SMALL_STATE_SWIM_UP_RELEASE:
		vy = 0;
		break;
	case JASON_SMALL_STATE_SWIM_DOWN:
		vy = JASON_SMALL_SWIMMING_DOWN_SPEED_Y;
		break;

	//DEAD
	case JASON_SMALL_STATE_DEAD:
		vx = 0;
		vy = 0;
		this->state = JASON_SMALL_STATE_DEAD;
		break;
	}
	CGameObject::SetState(state);
}

void CJasonSmall::SetKey(int KeyCode, int KeyState)
{
	//No key -1, Key down 0, Key up 1
	if (KeyState == -1)
	{
		if (isClimbing) this->SetState(JASON_SMALL_STATE_CLIMB);
		this->SetState(JASON_SMALL_STATE_IDLE);
	}
	else 
	{
		switch (KeyCode)
		{
		case DIK_LEFT:
			if (isSwimming) this->SetState(JASON_SMALL_STATE_SWIM_LEFT);
			else if (isCrawling) this->SetState(JASON_SMALL_STATE_CRAWLING_LEFT);
			else if (isClimbable && isClimbing) this->SetState(JASON_SMALL_STATE_CLIMB_LEFT);
			else this->SetState(JASON_SMALL_STATE_WALKING_LEFT);
			break;

		case DIK_RIGHT:
			if (isSwimming) this->SetState(JASON_SMALL_STATE_SWIM_RIGHT);
			else if (isCrawling) this->SetState(JASON_SMALL_STATE_CRAWLING_RIGHT);
			else if (isClimbable && isClimbing) this->SetState(JASON_SMALL_STATE_CLIMB_RIGHT);
			else this->SetState(JASON_SMALL_STATE_WALKING_RIGHT);
			break;

		case DIK_UP:
			if (isClimbable && !isClimbing) this->SetState(JASON_SMALL_STATE_CLIMB);
			else if (isClimbable && isClimbing) this->SetState(JASON_SMALL_STATE_CLIMB_UP);
			else if (isSwimming) this->SetState(JASON_SMALL_STATE_SWIM_UP);
			break;
		case DIK_DOWN:
			if (isClimbable && isClimbing) this->SetState(JASON_SMALL_STATE_CLIMB_DOWN);
			else if (isSwimming) this->SetState(JASON_SMALL_STATE_SWIM_DOWN);
			else this->SetState(JASON_SMALL_STATE_CRAWL);
			break;
		}
	}
	if (KeyCode == DIK_S)
	{
		if (KeyState == 0 && !isJumping && !isSwimming) this->SetState(JASON_SMALL_STATE_JUMP);
		else if (KeyState == 1 && !isSwimming && !isClimbing) this->SetState(JASON_SMALL_STATE_RELEASE_JUMP);
	}
	if (KeyCode == DIK_DOWN)
	{
		if (KeyState == 1 && isCrawling) this->SetState(JASON_SMALL_STATE_CRALW_RELEASE);
	}
	if (KeyCode == DIK_UP)
	{
		if (KeyState == 1 && isSwimming) this->SetState(JASON_SMALL_STATE_SWIM_UP_RELEASE);
	}
	
}

void CJasonSmall::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	if (!isClimbing)
	{
		if (isSwimming) vy += JASON_SMALL_GRAVITY_SWIM;
		else vy += JASON_SMALL_GRAVITY * dt;
	}

	if (y >= 160.0f)
	{
		vy = 0; y = 160.0f; isJumping = 0;
	}
	else if (isClimbing || isSwimming) isJumping = 0;
	else isJumping = 1;

	DebugOutTitle(L"isJumping = %0.5f", float(isJumping));

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void CJasonSmall::Render()
{
	int ani = ID_ANI_JASON_SMALL_IDLE_LEFT;

	if (nx < 0)
	{
		if (vx != 0)
		{
			if (isJumping) ani = ID_ANI_JASON_SMALL_JUMP_LEFT;
			else if (isSwimming) ani = ID_ANI_JASON_SMALL_SWIM_LEFT;
			else if (isCrawling) ani = ID_ANI_JASON_SMALL_CRAWLING_LEFT;
			else ani = ID_ANI_JASON_SMALL_WALKING_LEFT;
		}
		else if (isJumping) ani = ID_ANI_JASON_SMALL_JUMP_LEFT;
		else if (isSwimming) ani = ID_ANI_JASON_SMALL_SWIM_LEFT;
		else if (isCrawling) ani = ID_ANI_JASON_SMALL_CRAWL_IDLE_LEFT;
		else ani = ID_ANI_JASON_SMALL_IDLE_LEFT;
	}

	if (nx >= 0)
	{
		if (vx != 0)
		{
			if (isJumping) ani = ID_ANI_JASON_SMALL_JUMP_RIGHT;
			else if (isSwimming) ani = ID_ANI_JASON_SMALL_SWIM_RIGHT;
			else if (isCrawling) ani = ID_ANI_JASON_SMALL_CRAWLING_RIGHT;
			else ani = ID_ANI_JASON_SMALL_WALKING_RIGHT;
		}
		else if (isJumping) ani = ID_ANI_JASON_SMALL_JUMP_RIGHT;
		else if (isSwimming) ani = ID_ANI_JASON_SMALL_SWIM_RIGHT;
		else if (isCrawling) ani = ID_ANI_JASON_SMALL_CRAWL_IDLE_RIGHT;
		else ani = ID_ANI_JASON_SMALL_IDLE_RIGHT;
	}

	if (isClimbing)
	{
		if (vy > 0) ani = ID_ANI_JASON_SMALL_CLIMB_DOWN;
		else if (vy < 0) ani = ID_ANI_JASON_SMALL_CLIMB_UP;
		else ani = ID_ANI_JASON_SMALL_CLIMB_IDLE;
	}

	if (this->state == JASON_SMALL_STATE_DEAD)
	{
		ani = ID_ANI_JASON_SMALL_DEAD;
	}

	animations->Get(ani)->Render(x, y);
}

