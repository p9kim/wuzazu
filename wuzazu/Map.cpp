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
}
void Map::LoadMap(unsigned int level)
{
	switch (level)
	{
	case 1:
		mapPixels = readBMP(this, "assets/map.bmp");
		break;
	}
	return;
}

void Map::DrawMap()
{
	int type = 0;
	
	for (vector<Pixel*> row : mapPixels)
	{
		for (Pixel* pix : row)
		{

		}
	}

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
}



void Map::setPixels(deque<vector<Pixel*>> pixels)
{
	mapPixels = pixels;
}
deque<vector<Pixel*>> Map::getPixels()
{
	return mapPixels;
}
void Map::setHeight(unsigned int height)
{
	this->height = height;
}
unsigned int Map::getHeight()
{
	return height;
}
void Map::setWidth(unsigned int width)
{
	this->width = width;
}
unsigned int Map::getWidth()
{
	return width;
}
void Map::setName(string name)
{
	this->name = name;
}
string Map::getName()
{
	return name;
}