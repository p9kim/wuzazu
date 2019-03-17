#pragma once
#include "terrain.hpp"
#include "Pixel.hpp"
#include "Player.hpp"

class Team;
class Cell
{
private:
	Pixel pixel_;
	Player* player_;
	Terrain terrain_;
	Cell* N_;
	Cell* E_;
	Cell* S_;
	Cell* W_;
	unsigned int X;
	unsigned int Y;
	Team* owner_;
	Pixel regionColor_;
	unsigned int regionNumber_;
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
	void draw(SDL_Rect, SDL_Rect);
	void drawPlayer(SDL_Rect, SDL_Rect);
	bool selected;
	Cell* N();
	void N(Cell*);
	Cell* E();
	void E(Cell*);
	Cell* S();
	void S(Cell*);
	Cell* W();
	void W(Cell*);
	void setRegionColor(Pixel);
	Pixel regionColor();
	unsigned int regionNumber();
	void regionNumber(unsigned int);
};