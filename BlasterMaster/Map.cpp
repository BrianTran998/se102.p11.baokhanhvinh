#include "Map.h"
#include "Game.h"
#include "debug.h"

Map::Map(int ID, LPCWSTR FilePath_data, int Map_rows, int Map_cols, int Num_row_read, int Num_col_read, int Tile_width, int Tile_height)
{
	this->Id = ID;
	this->MapFilePath = FilePath_data;
	this->Num_Rows = Map_rows;
	this->Num_Cols = Map_cols;
	this->num_row_read = Num_row_read;
	this->num_col_read = Num_col_read;
	this->Tile_Width = Tile_width;
	this->Tile_Height = Tile_height;
	LoadMap();
	Load();
}

void Map::Load()
{
	ifstream f;
	f.open(MapFilePath);
	if (f.fail())
	{
		f.close();
		return;
	}

	for (int i = 0; i < Num_Rows; i++)
	{
		for (int j = 0; j < Num_Cols; j++)
		{
			int temp;
			f >> temp;
			tilemap[i][j] = temp + 1;
		}
	}

	f.close();
}

void Map::LoadMap()
{
	CTextures *texture = CTextures::GetInstance();
	LPTEXTURE texMap = texture->Get(Id);
	int id_sprite = 1;

	for (UINT i = 0; i < num_row_read; i++)
	{
		for (UINT j = 0; j < num_col_read; j++)
		{
			int id_Sprite = Id + id_sprite;
			sprites->Add(id_Sprite, Tile_Width * j, Tile_Height * i, (Tile_Width * j) + Tile_Width, (Tile_Height * i) + Tile_Height, texMap, 0);
			id_sprite = id_sprite + 1;
		}
	}
}

void Map::Draw()
{
	int firstcol = (int)CGame::GetInstance()->GetCamPosX() / 16;
	if (firstcol < 0)
	{
		firstcol = 0;
	}
	int lastcol = firstcol + 24;
	DebugOut(L"Cmx: %d\n", GetMapWidth());
	for (UINT i = 0; i < Num_Rows; i++)
	{
		for (UINT j = firstcol; j < lastcol; j++)
		{
			float x = Tile_Width * j + (Tile_Width / 2);
			float y = Tile_Height * i + (Tile_Height / 2);
			sprites->Get(tilemap[i][j] + Id)->Draw(x, y);
		}
	}
}

Map::~Map()
{
}