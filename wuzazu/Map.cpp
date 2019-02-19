#include "Map.hpp" 

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
		readBMP("assets/map.bmp");
		break;
	default:
		throw new exception("Invalid Map ID");
	}
	return;
}

void Map::DrawMap()
{
	int col = 0;
	int row = 0;
	for (vector<Cell*> cV : cells)
	{
		for (Cell* c : cV)
		{
			dest.x = col * 16;
			dest.y = row * 16;
			c->terrain().draw(src, dest);
			col++;
		}
		col = 0;
		row++;
	}
}

void Map::readBMP(const char* filename)
{
	water = *(new Water());
	dirt = *(new Dirt());
	grass = *(new Grass());

	Terrain* ter = 0;
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

	vector<Cell*>* row = new vector<Cell*>();
	for (int i = 0; i < height; i++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;
			Pixel* color = new Pixel((unsigned int)data[j], (unsigned int)data[j + 1], (unsigned int)data[j + 2]);
			if (*color == red || *color == yellow)
				ter = &dirt;
			else if (*color == green)
				ter = &grass;
			else if (*color == blue)
				ter = &water;
			else
			{
				ter = &water;
				cerr << "Unknown pixel color found at " << j << ", " << i << endl;
			}
			row->push_back(new Cell(*color, *ter, i, j/3));
			delete(color);
		}
		cells.push_front(*row);
		row->clear();

	}
	delete(row);
	fclose(f);
}
Cell Map::at(unsigned int x, unsigned int y)
{
	vector<Cell*> col = cells.at(y);
	return *col.at(x);
}

/* Getters / Setters */
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