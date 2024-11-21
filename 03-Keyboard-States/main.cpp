/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 03 - KEYBOARD AND OBJECT STATE

	This sample illustrates how to:

		1/ Process keyboard input
		2/ Control object state with keyboard events
================================================================ */

#include <windows.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "CJasonSmall.h"
#include "CWalker.h"
#include "Brick.h"
#include "CLadder.h"
#include "CCamera.h"
#include "CQuadTree.h"

#include "SampleKeyEventHandler.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"03 - Keyboard and Mario states"
#define WINDOW_ICON_PATH L"mario.ico"


#define BACKGROUND_COLOR D3DXCOLOR(200.0f/255, 200.0f/255, 255.0f/255, 0.0f)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define ID_TEX_MISC 20

#define ID_SPRITE_BRICK 20001

#define TEXTURES_DIR L"textures"
#define TEXTURE_PATH_MISC TEXTURES_DIR "\\misc.png"

#define JASON_SMALL_START_X 100.0f
#define JASON_SMALL_START_Y 200.0f

#define WALKER_START_X 100.0f
#define WALKER_START_Y 200.0f

#define GROUND_Y 160.0f
#define BRICK_X 0.0f
#define LADDER_X 200.0f
#define LADDER_HEIGHT 15.0f
#define BRICK_Y GROUND_Y - 20.0f
#define NUM_BRICKS 126
#define NUM_LADDER 10
#define NUM_WALKER 7

CJasonSmall* jason_small = NULL;
CCamera* camera = new CCamera(0, 200, SCREEN_WIDTH, SCREEN_HEIGHT);
CQuadTree* tree = NULL;

CSampleKeyHandler* keyHandler;

vector<LPGAMEOBJECT> objects;

CTextures* textures = CTextures::GetInstance();
CSprites* sprites = CSprites::GetInstance();
CAnimations* animations = CAnimations::GetInstance();

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

/*
	Load all game resources 
	In this example: load textures, sprites, animations and mario object
*/
void LoadResources()
{
	textures->Add(ID_TEX_MISC, TEXTURE_PATH_MISC);

	LPANIMATION ani;

	// Brick objects 
	LPTEXTURE texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(ID_SPRITE_BRICK, 372, 153, 372+15, 153+15, texMisc);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK);
	animations->Add(ID_ANI_BRICK,ani);

	CLadder::LoadResource();
	CJasonSmall::LoadResource();
	CWalker::LoadResource();

	for (int i = 0; i < NUM_LADDER; i++)
	{
		CLadder* l = new CLadder(LADDER_X, GROUND_Y + LADDER_HEIGHT * i);
		objects.push_back(l);
	}

	for (int i=0;i<NUM_BRICKS;i++) 
	{
		CBrick* b = new CBrick(BRICK_X + i * BRICK_WIDTH, BRICK_Y);
		objects.push_back(b);
	}

	jason_small = new CJasonSmall(JASON_SMALL_START_X, JASON_SMALL_START_Y);
	objects.push_back(jason_small);
	for (int i = 0; i < NUM_WALKER; i++)
	{
		CWalker* walker = new CWalker(WALKER_START_X + i * 250.0f, WALKER_START_Y);
		objects.push_back(walker);
	}
	tree = new CQuadTree(WORLD_WIDTH, WORLD_HEIGHT, objects);
	objects.clear();
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	vector<LPGAMEOBJECT> addobject = tree->getObjectsInView(camera);
	objects.insert(objects.end(), addobject.begin(), addobject.end());
	DebugOutTitle(L"objects.size() = %0.5f", float(objects.size()));
	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
}

void Render()
{
	CGame* g = CGame::GetInstance();

	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	IDXGISwapChain* pSwapChain = g->GetSwapChain();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3DX10Sprite* spriteHandler = g->GetSpriteHandler();

	pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

	spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

	FLOAT NewBlendFactor[4] = { 0,0,0,0 };
	pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);

	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects[i]->Render();
	}

	spriteHandler->End();
	pSwapChain->Present(0, 0);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd) 
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	ULONGLONG tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ULONGLONG now = GetTickCount64();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		ULONGLONG dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update((DWORD)dt);
			CGame::GetInstance()->ProcessKeyboard();
			Render();
		}
		else
			Sleep((DWORD)(tickPerFrame - dt));
	}

	return 1;
}

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	SetDebugWindow(hWnd);

	CGame* game = CGame::GetInstance();
	game->Init(hWnd, hInstance);

	keyHandler = new CSampleKeyHandler();
	game->InitKeyboard(keyHandler);

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	LoadResources();

	Run();

	return 0;
}