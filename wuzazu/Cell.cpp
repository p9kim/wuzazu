#include "Cell.hpp"

Cell::Cell(Pixel p, Terrain t, unsigned int x, unsigned int y, Player* player, unsigned int width, unsigned int height)
{
	pixel_ = p;
	terrain_ = t;
	this->X = x;
	this->Y = y;
	this->width = width;
	this->height = height;
	this->xPix = 0;
	this->yPix = 0;

	player_ = nullptr;
	inside = false;

	player_ = player;
}
unsigned int Cell::getWidth()
{
	return width;
}
unsigned int Cell::getHeight()
{
	return height;
}
void Cell::setWidth(unsigned int width)
{
	this->width = width;
}
void Cell::setHeight(unsigned int height)
{
	this->height = height;
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

unsigned int Cell::clickCell(unsigned int x, unsigned int y)
{
	if (x >= this->x() && x < (this->x() + this->getWidth()))
	{
		if (y >= this->y() && y < (this->y() + this->getHeight()))
		{
			cout << "mouse is in Cell: " << X << ", " << Y << endl;
			return 1;
		}
	}
	cout << "Doesn't work" << endl;
	return 0;
}

