#include "Cell.hpp"
#include "Render.hpp"

Cell::Cell(Pixel p, Terrain t, unsigned int x, unsigned int y, Player* player)
{
	pixel_ = p;
	terrain_ = t;
	this->X = x;
	this->Y = y;
	player_ = player;
	N_ = E_ = S_ = W_ = nullptr;
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
Cell* Cell::N()
{
	return N_;
}
void Cell::N(Cell* n)
{
	N_ = n;
}
Cell* Cell::E()
{
	return E_;
}
void Cell::E(Cell* e)
{
	E_ = e;
}
Cell* Cell::S()
{
	return S_;
}
void Cell::S(Cell* s)
{
	S_ = s;
}
Cell* Cell::W()
{
	return W_;
}
void Cell::W(Cell* w)
{
	W_ = w;
}
void Cell::draw(SDL_Rect src, SDL_Rect dest)
{
	terrain().draw(src, dest);
	if (hasPlayer())
		player()->render(src, dest);
	if (selected)
	{
		unsigned int xpos = X * 42;
		unsigned int ypos = Y * 42;
		SDL_Rect outlineRect = { xpos, ypos, 42, 42 };
		SDL_SetRenderDrawColor(renderer->getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawRect(renderer->getRenderer(), &outlineRect);
	}
}
