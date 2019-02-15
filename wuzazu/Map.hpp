#pragma once
#include "Game.hpp"
#include "Pixel.hpp"
#include "Player.hpp"
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
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	deque<vector<Pixel*>> map;
	deque<vector<Player*>> cells;

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
};
