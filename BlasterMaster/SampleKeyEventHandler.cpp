#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Jason.h"
#include "PlayScene.h"

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	CJason *jason = (CJason *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		jason->SetKey(DIK_S, 0);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	CJason *jason = (CJason *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		jason->SetKey(DIK_S, 1);
		break;
	case DIK_DOWN:
		jason->SetKey(DIK_DOWN, 1);
		break;
	case DIK_UP:
		jason->SetKey(DIK_UP, 1);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CJason *jason = (CJason *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGame *game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		jason->SetKey(DIK_RIGHT, 0);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		jason->SetKey(DIK_LEFT, 0);
	}
	else
	{
		jason->SetKey(DIK_LEFT, -1);
	}

	// Sitting state has higher priority
	if (game->IsKeyDown(DIK_DOWN))
	{
		jason->SetKey(DIK_DOWN, 0);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		jason->SetKey(DIK_UP, 0);
	}

	if (game->IsKeyDown(DIK_K))
	{
		jason->SetKey(DIK_K, 0);
	}
}