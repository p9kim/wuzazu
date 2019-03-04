#include "Map.hpp"
#include "HandleEvents.hpp"

Map::Map(Game* game)
{
	game_ = game;
	src.x = src.y = 0;
	src.w = dest.w = CELLSIZE;
	src.h = dest.h = CELLSIZE;
	dest.x = dest.y = 0;

	LoadMap(1);
	unsigned int x = 0, y = 0;
	for (vector<Cell*> cV : cells)
	{
		for (Cell* c : cV)
		{
			if (x < width - 1)
				c->E(cV.at(x + 1));
			if (x > 0)
				c->W(cV.at(x - 1));
			if (y < height - 1)
				c->S(cells.at(y + 1).at(x));
			if (y > 0)
				c->N(cells.at(y - 1).at(x));
			x++;
		}
		x = 0;
		y++;
	}
}

void Map::LoadMap(unsigned int level)
{
	switch (level)
	{
	case 1:
		readBMP("assets/map1.bmp", "assets/entities1.bmp");
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
			dest.x = col * CELLSIZE;
			dest.y = row * CELLSIZE;
			c->draw(src, dest);
			col++;
		}
		col = 0;
		row++;
	}
}

void Map::readBMP(const char* mapfile, const char* entityfile)
{
	water = *(new Water());
	dirt = *(new Dirt());
	grass = *(new Grass());

	Terrain* ter = 0;
	FILE* f = fopen(mapfile, "rb");
	FILE* ef = fopen(entityfile, "rb");

	if (f == NULL || ef == NULL)
		throw "File not found exception";

	unsigned char info[54];
	unsigned char info2[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
	fread(info2, sizeof(unsigned char), 54, ef);

	// extract image height and width from header
	const int width = *(int*)&info[18];
	const int height = *(int*)&info[22];
	const int width2 = *(int*)&info2[18];
	const int height2 = *(int*)&info2[22];

	//if (width != width2 && height != height2)
		//throw "The two file's height and width do not match each other";

	this->width = width;
	this->height = height;
	this->name = name;

	int row_padded = (width * 3 + 3) & (~3);
	int row_padded2 = (width2 * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];
	unsigned char* data2 = new unsigned char[row_padded2];
	unsigned char tmp, tmp2;

	vector<Cell*>* row = new vector<Cell*>();
	for (int i = 0; i < height; i++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		fread(data2, sizeof(unsigned char), row_padded2, ef);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j]; tmp2 = data2[j];
			data[j] = data[j + 2]; data2[j] = data2[j + 2];
			data[j + 2] = tmp; data2[j + 2] = tmp2;
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
			Player* player = nullptr;
			Pixel* color2 = new Pixel((unsigned int)data2[j], (unsigned int)data2[j + 1], (unsigned int)data2[j + 2]);
			if (*color2 == red) {
				game_->addTeam('y');
				player = new Rock('y');
			}
			else if (*color2 == orange) {
				game_->addTeam('y');
				player = new Paper('y');
			}
			else if (*color2 == yellow) {
				game_->addTeam('y');
				player = new Scissors('y');
			}
			else if (*color2 == green) {
				game_->addTeam('b');
				player = new Rock('b');
			}
			else if (*color2 == blue) {
				game_->addTeam('b');
				player = new Paper('b');
			}
			else if (*color2 == cyan) {
				game_->addTeam('b');
				player = new Scissors('b');
			}
			Cell* cell = new Cell(*color, *ter, j/3, width-i-1, player);
			if (player != nullptr)
				player->setCell(cell);
			row->push_back(cell);
			delete(color);
		}
		cells.push_front(*row);
		row->clear();

	}
	delete(row);
	fclose(f);
}
Cell* Map::at(unsigned int x, unsigned int y)
{
	vector<Cell*> col = cells.at(y);
	return col.at(x);
}

bool Map::handleClick(int x, int y)
{
	Cell* clickedCell = at((unsigned int)floor(x / CELLSIZE), (unsigned int)floor(y / CELLSIZE));
	EventHandler.clickCell(clickedCell);
	return true;
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
Game* Map::game()
{
	return game_;
}
void Map::game(Game* g)
{
	game_ = g;
}