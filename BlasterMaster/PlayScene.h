#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Jason.h"
#include "Sophia.h"
#include "AutoMover.h"
#include "Walker.h"

class CPlayScene : public CScene
{
protected:
	LPGAMEOBJECT player;
	LPGAMEOBJECT player2;

	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_MAP(string line);

	void LoadAssets(LPCWSTR assetFile);

public:
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }
	LPGAMEOBJECT GetPlayer2() { return player2; }
	LPGAMEOBJECT GetActivePlayer()
	{
		CSophia *sophia = (CSophia *)player;
		CJason *jason = (CJason *)player2;
		if (jason->isDisplayJason == 1)
		{
			return player2;
		}
		else
		{
			return player;
		}
	}

	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT &o);
};

typedef CPlayScene *LPPLAYSCENE;
