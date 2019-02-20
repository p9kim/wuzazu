#pragma once
#include "terrain.hpp"
#include "Pixel.hpp"
#include "Player.hpp"

class Cell
{
private:
	Pixel pixel_;
	Player* player_;
	Terrain terrain_;
	unsigned int X;
	unsigned int Y;
	bool inside;
public:
	Cell(Pixel, Terrain, unsigned int, unsigned int, Player*);
	void setPixel(Pixel);
	Pixel pixel();
	void setPlayer(Player*);
	Player* player();
	bool hasPlayer();
	void setTerrain(Terrain);
	Terrain terrain();
	unsigned int x();
	unsigned int y();

	//void clickEvent(SDL_Event*);

	pair<unsigned int, unsigned int> getCenter();
	void draw(SDL_Rect src, SDL_Rect dest);

};