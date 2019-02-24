#include "Cell.hpp"

Cell::Cell(Pixel p, Terrain t, unsigned int x, unsigned int y, Player* player)
{
	pixel_ = p;
	terrain_ = t;
	this->X = x;
	this->Y = y;
	player_ = player;
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
	return X;
}
unsigned int Cell::y()
{
	return Y;
}
pair<unsigned int, unsigned int> Cell::getCenter()
{
	return make_pair(X + (42 / 2), Y + (42 / 2));
}
void Cell::draw(SDL_Rect src, SDL_Rect dest)
{
	terrain().draw(src, dest);
	if (hasPlayer())
		player()->render(src, dest);
}
void Cell::drawSelected()
{

}
