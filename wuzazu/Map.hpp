#pragma once
#include "Game.hpp"
#include "Pixel.hpp"
#include "Player.hpp"
#include "terrain.hpp"
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

	deque<vector<Pixel*>> mapPixels;
	deque<vector<Terrain*>> terrain;
	vector<vector<Player*>> cells;

public:

	Map();
	~Map();

	void LoadMap(unsigned int level);
	void DrawMap();
	deque<vector<Pixel*>> readBMP(const char* filename);

	void setPixels(deque<vector<Pixel*>>);
	deque<vector<Pixel*>> getPixels();
	void setHeight(unsigned int);
	unsigned int getHeight();
	void setWidth(unsigned int);
	unsigned int getWidth();
	void setName(string);
	string getName();
	bool canMoveTo(unsigned int x, unsigned int y);
};
