#include "Map.hpp"
#include "terrain.hpp"
#include <iostream>

Map::Map()
{
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;

	LoadMap(1);
}

void Map::LoadMap(unsigned int level)
{
	switch (level)
	{
	case 1:
		setPixels(readBMP("assets/map.bmp"));
		break;
	default:
		throw new exception("Invalid Map ID");
	}
	return;
}

void Map::DrawMap()
{
	Red* red = new Red();
	Green* green = new Green();
	Blue* blue = new Blue();
	Yellow* yellow = new Yellow();

	int col = 0;
	int row = 0;
	Terrain* ter;
	vector<Terrain*> terrainRow;
	for (vector<Pixel*> pV : mapPixels)
	{
		for (Pixel* px : pV)
		{
			dest.x = col * 16;
			dest.y = row * 16;
			if (*px == *red || *px == *yellow)
			{
				ter = new Dirt();
				ter->draw(src, dest);
				terrainRow.push_back(ter);
			}
			else if (*px == *green)
			{
				ter = new Grass();
				ter->draw(src, dest);
				terrainRow.push_back(ter);
			}
			else if (*px == *blue)
			{
				ter = new Water();
				ter->draw(src, dest);
				terrainRow.push_back(ter);
			}
			else
			{
				ter = new Water();
				ter->draw(src, dest);
				terrainRow.push_back(ter);
				cerr << "Unknown pixel color found at " << col << ", " << row << endl;
			}
			col++;
		}
		terrain.push_front(terrainRow);
		terrainRow.clear();
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
bool Map::canMoveTo(unsigned int x, unsigned int y)
{
	if (cells.at(y).at(x) == nullptr)
		if(mapPixels.at(y).at(x) != /*water*/ false)
			return true;
	return true;
}
/* Getters / Setters */
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