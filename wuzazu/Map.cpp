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

	LoadMap(1);

	cout << "Loaded " << this->name << endl;
	cout << this->width << endl;
	cout << this->height << endl;
}

void Map::LoadMap(unsigned int level)
{
	switch (level)
	{
	case 1:
		map = readBMP("assets/map.bmp");
		break;
	default:
		throw new exception("Invalid Map ID");
	}
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

			dest.x = col * 16;
			dest.y = row * 16;
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
}

deque<vector<Pixel*>> Map::readBMP(const char* filename)
{
	FILE* f = fopen(filename, "rb");

	if (f == NULL)
		throw "Argument Exception";

	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	const int width = *(int*)&info[18];
	const int height = *(int*)&info[22];

	this->width = width;
	this->height = height;
	this->name = name;

	int row_padded = (width * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];
	unsigned char tmp;

	deque<vector<Pixel*>> pixels;
	vector<Pixel*>* row = new vector<Pixel*>();
	for (int i = 0; i < height; i++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;

			row->push_back(new Pixel((unsigned int)data[j], (unsigned int)data[j + 1], (unsigned int)data[j + 2]));
		}
		pixels.push_front(*row);
		row->clear();
	}
	delete(row);
	fclose(f);
	return pixels;
}

/* Getters / Setters */
void Map::setPixels(deque<vector<Pixel*>> pixels)
{
	map = pixels;
}
deque<vector<Pixel*>> Map::getPixels()
{
	return map;
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