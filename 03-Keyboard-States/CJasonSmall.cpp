#include "CJasonSmall.h"

void CJasonSmall::LoadResource()
{
	textures->Add(ID_TEX_PLAYER, TEXTURE_PATH_PLAYER);

	LPTEXTURE textJasonSmall = textures->Get(ID_TEX_PLAYER);

	LPANIMATION ani;

	//Jason small idle left
	sprites->Add(3000001, 3, 30, 10, 45, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(3000001);
	animations->Add(ID_ANI_JASON_SMALL_IDLE_LEFT, ani);

	//Jason small idle right
	sprites->Add(3000002, 10, 30, 3, 45, textJasonSmall, -1);

	ani = new CAnimation(100);
	ani->Add(3000002);
	animations->Add(ID_ANI_JASON_SMALL_IDLE_RIGHT, ani);

	//Jason small walk left
	sprites->Add(3000003, 12, 30, 19, 45, textJasonSmall);
	sprites->Add(3000004, 21, 30, 28, 45, textJasonSmall);
	sprites->Add(3000005, 30, 30, 37, 45, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(3000003);
	ani->Add(3000004);
	ani->Add(3000005);
	ani->Add(3000004);
	animations->Add(ID_ANI_JASON_SMALL_WALKING_LEFT, ani);

	//Jason small walk right
	sprites->Add(3000006, 19, 30, 12, 45, textJasonSmall, -1);
	sprites->Add(3000007, 28, 30, 21, 45, textJasonSmall, -1);
	sprites->Add(3000008, 37, 30, 30, 45, textJasonSmall, -1);

	ani = new CAnimation(100);
	ani->Add(3000006);
	ani->Add(3000007);
	ani->Add(3000008);
	ani->Add(3000007);
	animations->Add(ID_ANI_JASON_SMALL_WALKING_RIGHT, ani);

	//Jason small crawl left
	sprites->Add(3000009, 3, 47, 18, 54, textJasonSmall);
	sprites->Add(3000010, 20, 47, 35, 54, textJasonSmall);

	ani = new CAnimation(120);
	ani->Add(3000009);
	animations->Add(ID_ANI_JASON_SMALL_CRAWL_IDLE_LEFT, ani);

	ani = new CAnimation(120);
	ani->Add(3000009);
	ani->Add(3000010);
	animations->Add(ID_ANI_JASON_SMALL_CRAWLING_LEFT, ani);

	//Jason small crawl right
	sprites->Add(3000011, 18, 47, 3, 54, textJasonSmall, -1);
	sprites->Add(3000012, 35, 47, 20, 54, textJasonSmall, -1);

	ani = new CAnimation(120);
	ani->Add(3000011);
	animations->Add(ID_ANI_JASON_SMALL_CRAWL_IDLE_RIGHT, ani);

	ani = new CAnimation(120);
	ani->Add(3000011);
	ani->Add(3000012);
	animations->Add(ID_ANI_JASON_SMALL_CRAWLING_RIGHT, ani);

	//Jason small jump left
	ani = new CAnimation(100);
	ani->Add(3000003);
	animations->Add(ID_ANI_JASON_SMALL_JUMP_LEFT, ani);

	//Jason small jump right
	ani = new CAnimation(100);
	ani->Add(3000006);
	animations->Add(ID_ANI_JASON_SMALL_JUMP_RIGHT, ani);

	//Jason small climb ladder
	sprites->Add(3000013, 40, 47, 49, 62, textJasonSmall);
	sprites->Add(3000014, 57, 47, 66, 62, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(3000013);
	animations->Add(ID_ANI_JASON_SMALL_CLIMB_IDLE, ani);

	ani = new CAnimation(100);
	ani->Add(3000013);
	ani->Add(3000014);
	animations->Add(ID_ANI_JASON_SMALL_CLIMB_UP, ani);

	ani = new CAnimation(100);
	ani->Add(3000014);
	ani->Add(3000013);
	animations->Add(ID_ANI_JASON_SMALL_CLIMB_DOWN, ani);

	//Jason small swim left
	sprites->Add(3000015, 39, 36, 53, 45, textJasonSmall);
	sprites->Add(3000016, 56, 36, 70, 45, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(3000015);
	ani->Add(3000016);
	animations->Add(ID_ANI_JASON_SMALL_SWIM_LEFT, ani);

	//Jason small swim right
	sprites->Add(3000017, 53, 36, 39, 45, textJasonSmall, -1);
	sprites->Add(3000018, 70, 36, 56, 45, textJasonSmall, -1);

	ani = new CAnimation(100);
	ani->Add(3000017);
	ani->Add(3000018);
	animations->Add(ID_ANI_JASON_SMALL_SWIM_RIGHT, ani);

	//Jason small dead
	sprites->Add(3000019, 3, 64, 18, 79, textJasonSmall);
	sprites->Add(3000020, 20, 64, 35, 79, textJasonSmall);
	sprites->Add(3000021, 37, 64, 52, 79, textJasonSmall);
	sprites->Add(3000022, 54, 64, 69, 79, textJasonSmall);
	sprites->Add(3000023, 3, 81, 18, 96, textJasonSmall);
	sprites->Add(3000024, 20, 89, 35, 96, textJasonSmall);

	ani = new CAnimation(100);
	ani->Add(3000019);
	ani->Add(3000020);
	ani->Add(3000021);
	ani->Add(3000022);
	ani->Add(3000023);
	ani->Add(3000024);
	animations->Add(ID_ANI_JASON_SMALL_DEAD, ani);

	//Jason big turn down
	sprites->Add(3000025, 208, 3, 231, 34, textJasonSmall);
	sprites->Add(3000026, 233, 3, 256, 34, textJasonSmall);
	sprites->Add(3000027, 258, 3, 281, 34, textJasonSmall);

	//Jason big turn up
	sprites->Add(3000028, 208, 36, 231, 67, textJasonSmall);
	sprites->Add(3000029, 233, 36, 256, 67, textJasonSmall);
	sprites->Add(3000030, 258, 36, 281, 67, textJasonSmall);

	//Jason big turn left
	sprites->Add(3000031, 208, 69, 231, 100, textJasonSmall);
	sprites->Add(3000032, 233, 69, 256, 100, textJasonSmall);
	sprites->Add(3000033, 258, 69, 281, 100, textJasonSmall);

	//Jason big dead
	sprites->Add(3000034, 283, 3, 306, 34, textJasonSmall);
	sprites->Add(3000035, 308, 3, 331, 34, textJasonSmall);
	sprites->Add(3000036, 333, 3, 356, 34, textJasonSmall);
	sprites->Add(3000037, 358, 3, 381, 34, textJasonSmall);
	sprites->Add(3000038, 383, 19, 406, 34, textJasonSmall);
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
		if (isJumping == 1) break;
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
	case JASON_SMALL_STATE_SWIM_RELEASE:
		isSwimming = 0;
		if (!isClimbing) SetState(JASON_SMALL_STATE_JUMP);
		break;
	case JASON_SMALL_STATE_SWIM_ENTER:
		if (isSwimming) break;
		isSwimming = 1;
		vy = 0;
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

	int SWIM_DEMO = 0;
	if (SWIM_DEMO)
	{
		if (y >= 100.0f)
		{
			SetState(JASON_SMALL_STATE_SWIM_ENTER);
		}
		else SetState(JASON_SMALL_STATE_SWIM_RELEASE);
	}

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
	else if (nx >= 0)
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
		if (vy > 0 || vx!=0) ani = ID_ANI_JASON_SMALL_CLIMB_DOWN;
		else if (vy < 0) ani = ID_ANI_JASON_SMALL_CLIMB_UP;
		else ani = ID_ANI_JASON_SMALL_CLIMB_IDLE;
	}

	if (this->state == JASON_SMALL_STATE_DEAD)
	{
		ani = ID_ANI_JASON_SMALL_DEAD;
	}

	animations->Get(ani)->Render(x, y);
}

