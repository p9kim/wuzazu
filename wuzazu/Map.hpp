#pragma once
#include "Game.hpp"
#include "readBMP.hpp"

class Map
{
public:

	Map();
	~Map();

	void LoadMap(deque<vector<Pixel*>>);
	void DrawMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};
