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

	void setHeight(unsigned int);
	unsigned int getHeight();
	void setWidth(unsigned int);
	unsigned int getWidth();
	void setName(string);
	string getName();

private:

	string name;
	unsigned int height;
	unsigned int width;
	
	deque<vector<Pixel*>> mapPixels;

	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};
