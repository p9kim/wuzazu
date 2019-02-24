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
	pair<unsigned int, unsigned int> getCenter();
	void draw(SDL_Rect, SDL_Rect);
	void drawSelected();
	void drawHighlight();
};