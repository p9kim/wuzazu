#pragma once
#include "Game.hpp"
#include "Cell.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <array>

static const unsigned int CS = 42;

class Map
{
private:

	string name;
	unsigned int width;
	unsigned int height;

	SDL_Rect src, dest;
	deque<vector<Cell*>> cells;
	unordered_map<unsigned int, vector<Cell*>> regions;
	vector<pair<pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int>>> region_borders;
	Game* game_;

public:

	Map(Game*);
	~Map();

	void LoadMap(unsigned int);
	void DrawMap();
	void readBMP(const char*, const char*, const char*);
	void buildRegions();
	Cell* at(unsigned int, unsigned int);
	void handleClick(int, int);
	void handleMouseHover(int, int);

	void setHeight(unsigned int);
	unsigned int getHeight();
	void setWidth(unsigned int);
	unsigned int getWidth();
	void setName(string);
	string getName();
	Game* game();
	void game(Game*);
};
