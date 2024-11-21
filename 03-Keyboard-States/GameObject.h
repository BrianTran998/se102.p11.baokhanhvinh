#pragma once

#include <Windows.h>
#include <d3dx10.h>
#include <vector>
#include "Common.h"

using namespace std;

class CGameObject
{
protected:
	//Location
	float x; 
	float y;
	//Size
	int width = 0;
	int height = 0;
	//Velocity
	float vx;
	float vy;
	//Direction
	int nx;	 

	int state;									
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }

	void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }

	bool isInSceneNode(float scenex, float sceney, float scenew, float sceneh);

	CGameObject();
	CGameObject(float x, float y):CGameObject() { this->x = x; this->y = y; }

	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
	~CGameObject();
};

typedef CGameObject* LPGAMEOBJECT;