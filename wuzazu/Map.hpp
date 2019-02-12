#pragma once
#include "Game.hpp"
#include "readBMP.hpp"

class Map
{
public:

	Map();
	~Map();

	void LoadMap(unsigned int level);
	void setPixels(deque<vector<Pixel*>>);
	deque<vector<Pixel*>> getPixels();
	void DrawMap();

private:

	deque<vector<Pixel*>> mapPixels;

	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};
