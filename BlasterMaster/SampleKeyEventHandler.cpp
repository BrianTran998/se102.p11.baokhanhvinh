#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Jason.h"
#include "Sophia.h"
#include "PlayScene.h"

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	CSophia *sophia = (CSophia *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		sophia->SetKey(DIK_S, 0);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	CSophia *sophia = (CSophia *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		sophia->SetKey(DIK_S, 1);
		break;
	case DIK_DOWN:
		sophia->SetKey(DIK_DOWN, 1);
		break;
	case DIK_UP:
		sophia->SetKey(DIK_UP, 1);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CSophia *sophia = (CSophia *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGame *game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		sophia->SetKey(DIK_RIGHT, 0);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		sophia->SetKey(DIK_LEFT, 0);
	}
	else
	{
		sophia->SetKey(DIK_LEFT, -1);
	}

	// Sitting state has higher priority
	if (game->IsKeyDown(DIK_DOWN))
	{
		sophia->SetKey(DIK_DOWN, 0);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		sophia->SetKey(DIK_UP, 0);
	}

	if (game->IsKeyDown(DIK_K))
	{
		sophia->SetKey(DIK_K, 0);
	}
}