#include "Cell.hpp"
Cell::Cell(Pixel p, Terrain t, unsigned int x, unsigned int y)
{
	pixel_ = p;
	terrain_ = t;
	this->X = x;
	this->Y = y;
	player_ = nullptr;
	inside = false;
}
void Cell::setPixel(Pixel pixel)
{
	pixel_ = pixel;
}

Pixel Cell::pixel()
{
	return pixel_;
}

void Cell::setPlayer(Player* player)
{
	player_ = player;
}

Player* Cell::player()
{
	return player_;
}

bool Cell::hasPlayer()
{
	if (player_ == nullptr)
		return false;
	else
		return true;
}
void Cell::setTerrain(Terrain terrain)
{
	this->terrain_ = terrain;
}
Terrain Cell::terrain()
{
	return terrain_;
}
unsigned int Cell::x()
{
	cout << "Cell is at x: " << X << endl;
	return X;
}
unsigned int Cell::y()
{
	cout << "Cell is at y: " << Y << endl;
	return Y;
}
