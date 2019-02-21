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
	unsigned int xPix;
	unsigned int yPix;
	unsigned int width;
	unsigned int height;
	bool inside;

public:
	Cell(Pixel, Terrain, unsigned int, unsigned int, Player*, unsigned int, unsigned int);
	void setPixel(Pixel);
	Pixel pixel();
	void setPlayer(Player*);
	Player* player();
	bool hasPlayer();
	void setTerrain(Terrain);
	Terrain terrain();
	unsigned int x();
	unsigned int y();
	unsigned int getWidth();
	unsigned int getHeight();
	void setWidth(unsigned int);
	void setHeight(unsigned int);
	void setXPix(unsigned int);
	void setYPix(unsigned int);
	unsigned int clickCell(unsigned int, unsigned int);


	pair<unsigned int, unsigned int> getCenter();
	void draw(SDL_Rect src, SDL_Rect dest);

};