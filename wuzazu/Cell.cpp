#include "Cell.hpp"
Cell::Cell(Pixel p, Terrain t)
{
	pixel_ = p;
	terrain_ = t;
}
void Cell::setPixel(Pixel pixel)
{
	pixel_ = pixel;
}

Pixel Cell::pixel()
{
	return pixel_;
}
/*
void Cell::setPlayer(Player player)
{
	player_ = player;
}

Player Cell::player()
{
	return player_;
}

bool Cell::hasPlayer()
{
	return false;
}
*/
void Cell::setTerrain(Terrain terrain)
{
	this->terrain_ = terrain;
}

Terrain Cell::terrain()
{
	return terrain_;
}
