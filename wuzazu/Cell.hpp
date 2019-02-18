#pragma once
#include "terrain.hpp"
#include "Pixel.hpp"
#include "Player.hpp"
class Cell
{
private:
	Pixel pixel_;
	//Player player_;
	Terrain terrain_;
public:
	Cell(Pixel, Terrain);
	void setPixel(Pixel);
	Pixel pixel();
	void setPlayer(Player);
	//Player player();
	//bool hasPlayer();
	void setTerrain(Terrain);
	Terrain terrain();
};