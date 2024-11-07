#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "CJasonSmall.h"


extern CJasonSmall* jason_small;

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		jason_small->SetKey(DIK_S, 0);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		jason_small->SetKey(DIK_S, 1);
		break;
	case DIK_DOWN:
		jason_small->SetKey(DIK_DOWN, 1);
		break;
	case DIK_UP:
		jason_small->SetKey(DIK_UP, 1);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		jason_small->SetKey(DIK_RIGHT, 0);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		jason_small->SetKey(DIK_LEFT, 0);
	}
	else {
		jason_small->SetKey(DIK_LEFT, -1);
	}
	
	// Sitting state has higher priority 
	if (game->IsKeyDown(DIK_DOWN))
	{
		jason_small->SetKey(DIK_DOWN, 0);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		jason_small->SetKey(DIK_UP, 0);
	}

}