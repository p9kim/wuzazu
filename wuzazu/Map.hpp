#pragma once
#include "Game.hpp"
#include "Cell.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

class Map
{
private:

	string name;
	unsigned int width;
	unsigned int height;

	SDL_Rect src, dest;
	deque<vector<Cell*>> cells;

public:
	static const unsigned int cellSize = 42;
	Map();
	~Map();

	void LoadMap(unsigned int);
	void DrawMap();
	void readBMP(const char*, const char*);
	Cell at(unsigned int, unsigned int);
	Cell getCellAtPos(unsigned int, unsigned int);

	void setHeight(unsigned int);
	unsigned int getHeight();
	void setWidth(unsigned int);
	unsigned int getWidth();
	void setName(string);
	string getName();
	//unsigned int clickCell(unsigned int, unsigned int, SDL_Rect);
};
