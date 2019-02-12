#include "Map.hpp"
#include "TextureManager.h"

Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;

	Pixel* p = new Pixel();
	map = p->readBMP("assets/map.bmp"); //49,50 = 50,50

	cout << "hi";

}

void Map::LoadMap(deque<vector<Pixel*>> lvl)
{
	return;
}

void Map::DrawMap()
{
	int r = 255;
	int g = 255;
	int b = 255;

	int col = 0;
	int row = 0;

	for (vector<Pixel*> pV : map)
	{
		for (Pixel* px : pV)
		{

			dest.x = col * 12;
			dest.y = row * 12;
			if (px->R() == r && px->G() == 0 && px->B() == 0)
			{
				TextureManager::Draw(dirt, src, dest);
			}
			else if (px->R() == 0 && px->G() == g && px->B() == 0)
			{
				TextureManager::Draw(grass, src, dest);
			}
			else
			{
				TextureManager::Draw(water, src, dest);
			}
			col++;
		}
		col = 0;
		row++;
	}
	/*
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			default:
				break;
			}
		}
	}
	*/
}