#pragma once
#include "Game.hpp"
#include "Cell.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

static const unsigned int CELLSIZE = 42;

class Map
{
private:

	string name;
	unsigned int width;
	unsigned int height;

	SDL_Rect src, dest;
	deque<vector<Cell*>> cells;

	Game* game_;

public:

	Map(Game*);
	~Map();

	void LoadMap(unsigned int);
	void DrawMap();
	void readBMP(const char*, const char*);
	Cell* at(unsigned int, unsigned int);
	void switchTurn();

	void setHeight(unsigned int);
	unsigned int getHeight();
	void setWidth(unsigned int);
	unsigned int getWidth();
	void setName(string);
	string getName();
	bool handleClick(int, int);
	Game* game();
	void game(Game*);
};
