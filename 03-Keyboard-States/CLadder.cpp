#include "CLadder.h"

void CLadder::LoadResource()
{
	textures->Add(ID_TEX_TILESET, TEXTURE_PATH_TILESET);

	LPTEXTURE textLadder = textures->Get(ID_TEX_TILESET);

	LPANIMATION ani;

	//Ladder sprite
	sprites->Add(5000001, 81, 61, 96, 76, textLadder);

	ani = new CAnimation(100);
	ani->Add(5000001);
	animations->Add(ID_ANI_LADDER, ani);
}

void CLadder::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_LADDER)->Render(x, y);
}


