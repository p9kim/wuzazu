#include "Map.hpp"
#include "HandleEvents.hpp"

Map::Map(Game* game)
{
	game_ = game;
	EventHandler.setGame(game_);
	src.x = src.y = 0;
	src.w = dest.w = CS;
	src.h = dest.h = CS;
	dest.x = dest.y = 0;
	LoadMap(3);
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
	buildRegions();
	game_->switchTurn();
}

void Map::LoadMap(unsigned int level)
{
	switch (level)
	{
	case 1:
		readBMP("assets/map1.bmp", "assets/entities1.bmp", "assets/regions1.bmp");
		break;
	case 2:
		readBMP("assets/map2.bmp", "assets/entities2.bmp", "assets/regions2.bmp");
		break;
	case 3:
		readBMP("assets/map3.bmp", "assets/entities3.bmp", "assets/regions4.bmp");
		break;	
	default:
		throw new exception("Invalid Map ID");
	}
}

void Map::DrawMap()
{
	SDL_Rect camBox = { renderer->getCamera().x*-1, renderer->getCamera().y*-1, 42, 42 };
	for (vector<Cell*> cV : cells)
	{
		for (Cell* c : cV)
		{
			c->draw(src, camBox);
			if(region_owners[c->regionNumber()].name() != "")
				c->drawRegionColor(camBox, region_owners[c->regionNumber()].color());
			c->drawPlayer(src, camBox);
			camBox.x += CS;
			if (camBox.x > renderer->winBox().w)
				break;
		}
		camBox.x = renderer->getCamera().x*-1;
		camBox.y += CS;
		if (camBox.y > renderer->winBox().h)
			break;
	}
	for (pair<pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int>> p : region_borders)
	{
		int sx, sy, ex, ey;
		SDL_SetRenderDrawColor(renderer->getRenderer(), 0, 0, 0, 100);
		sx = p.first.first - renderer->getCamera().x;
		sy = p.first.second - renderer->getCamera().y;
		ex = p.second.first - renderer->getCamera().x;
		ey = p.second.second - renderer->getCamera().y;
		SDL_RenderDrawLine(renderer->getRenderer(), sx, sy, ex, ey);
	}
}

void Map::readBMP(const char* mapfile, const char* entityfile, const char* regionfile)
{
	Terrain* ter = 0;
	FILE* f = fopen(mapfile, "rb");
	FILE* ef = fopen(entityfile, "rb");
	FILE* rf = fopen(regionfile, "rb");

	if (f == NULL || ef == NULL)
		throw "File not found exception";

	unsigned char info[54], info2[54], info3[54];
	fread(info, sizeof(unsigned char), 54, f); //read the 54-byte header
	fread(info2, sizeof(unsigned char), 54, ef);
	fread(info3, sizeof(unsigned char), 54, rf);

	// extract image height and width from header
	const int width = *(int*)&info[18], width2 = *(int*)&info2[18], width3 = *(int*)&info3[18];
	const int height = *(int*)&info[22], height2 = *(int*)&info2[22], height3 = *(int*)&info3[22];

	//if (width != width2 && height != height2)
		//throw "The two file's height and width do not match each other";

	this->width = width;
	this->height = height;
	this->name = name;

	int row_padded = (width * 3 + 3) & (~3), row_padded2 = (width2 * 3 + 3) & (~3), row_padded3 = (width3 * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];
	unsigned char* data2 = new unsigned char[row_padded2];
	unsigned char* data3 = new unsigned char[row_padded3];
	unsigned char tmp, tmp2, tmp3;

	vector<Cell*>* row = new vector<Cell*>();
	for (int i = 0; i < height; i++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		fread(data2, sizeof(unsigned char), row_padded2, ef);
		fread(data3, sizeof(unsigned char), row_padded3, rf);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j]; tmp2 = data2[j]; tmp3 = data3[j];
			data[j] = data[j + 2]; data2[j] = data2[j + 2]; data3[j] = data3[j + 2];
			data[j + 2] = tmp; data2[j + 2] = tmp2; data3[j + 2] = tmp3;
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
				game_->addTeam(YellowTeam);
				player = new Rock(&YellowTeam);
			}
			else if (*color2 == orange) {
				game_->addTeam(YellowTeam);
				player = new Paper(&YellowTeam);
			}
			else if (*color2 == yellow) {
				game_->addTeam(YellowTeam);
				player = new Scissors(&YellowTeam);
			}
			else if (*color2 == green) {
				game_->addTeam(BlueTeam);
				player = new Rock(&BlueTeam);
			}
			else if (*color2 == blue) {
				game_->addTeam(BlueTeam);
				player = new Paper(&BlueTeam);
			}
			else if (*color2 == cyan) {
				game_->addTeam(BlueTeam);
				player = new Scissors(&BlueTeam);
			}
			if (player != 0)
				game_->addPlayer(player);
			Pixel* regionColor = new Pixel((unsigned int)data3[j], (unsigned int)data3[j + 1], (unsigned int)data3[j + 2]);
			Cell* cell = new Cell(*color, *ter, j / 3, height - i - 1, player);
			if (player != nullptr)
				player->cell(cell);
			cell->setRegionColor(*regionColor);
			row->push_back(cell);
			delete(color);
		}
		cells.push_front(*row);
		row->clear();

	}
	delete(row);
	fclose(f);
	fclose(ef);
	fclose(rf);
}

void Map::buildRegions()
{
	Pixel curColor;
	unsigned int regionNumber = 0;
	unordered_map<Cell*, bool> isRegion;
	deque<Cell*> curRegion;
	Cell* temp;
	auto buildSubRegion = [&](Cell* cell, char dir)
	{
		if (!cell) return;
		unordered_map<char, array<int, 4>> coord = { {'N', {0,0,CS,0}},	{'E', {CS,0,CS,CS}}, {'S', {0,CS,CS,CS}}, {'W', {0,0,0,CS}} };
		if (!isRegion[cell] && cell->regionColor() == curColor)
		{
			curRegion.push_back(cell);
			regions[regionNumber].push_back(cell);
			isRegion[cell] = true;
			cell->regionNumber(regionNumber);
		}
		if (!isRegion[cell] && !(cell->regionColor() == curColor))
			region_borders.push_back(make_pair(
				make_pair(temp->x()*CS + (coord[dir][0]), temp->y()*CS + (coord[dir][1])), //x,y start
				make_pair(temp->x()*CS + (coord[dir][2]), temp->y()*CS + (coord[dir][3]))  //x,y dest
			));
	};
	for (vector<Cell*> cV : cells)
	{
		for (Cell* c : cV)
		{
			if (!(c->regionColor() == curColor) && !isRegion[c])
			{
				curColor = c->regionColor();
				//bfs
				curRegion.push_back(c);
				regions[regionNumber].push_back(c);
				isRegion[c] = true;
				c->regionNumber(regionNumber);
				while (!curRegion.empty())
				{
					temp = curRegion.front();
					curRegion.pop_front();
					buildSubRegion(temp->N(), 'N');
					buildSubRegion(temp->E(), 'E');
					buildSubRegion(temp->S(), 'S');
					buildSubRegion(temp->W(), 'W');
				}
				regionNumber++;
			}
		}
	}
	for (const auto& key : regions)		//set region owners
	{
		for (auto t : game_->teams())
			if (t.color() == key.second[0]->regionColor())
				region_owners[key.first] = t;
	}
}

Cell* Map::at(unsigned int x, unsigned int y) 
{
	x = (int)floor((x + renderer->getCamera().x) / CS);
	y = (int)floor((y + renderer->getCamera().y) / CS);
	vector<Cell*> col = cells.at(y);
	return col.at(x);
}

void Map::handleClick(int x, int y)
{
	cout << x << "," << y << " - " << renderer->getCamera().x << "," << renderer->getCamera().y << endl;
	Cell* clickedCell = at(x, y);
	EventHandler.clickCell(clickedCell);
	cout << "Region " << clickedCell->regionNumber() << " owned by: " << region_owners[clickedCell->regionNumber()].name() << endl;
}

void Map::handleMouseHover(int x, int y)
{
	Cell* hoveredCell = at(x, y);
	if (!hoveredCell)
		return;
	EventHandler.hoverCell(hoveredCell);
	EventHandler.hoverMap(x, y, hoveredCell);
}
void Map::captureRegion()
{
	Player* activePlayer = EventHandler.getActivePlayer();
	if (activePlayer == 0)
		return;
	region_owners[activePlayer->cell()->regionNumber()] = *(activePlayer->team());
	EventHandler.deactivatePlayer();
	activePlayer->done(true);
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