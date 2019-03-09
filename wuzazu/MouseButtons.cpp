#include "MouseButtons.hpp"

Mouse::Mouse()
{
	mPosition.x = 0;
	mPosition.y = 0;

	mCurrSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void Mouse::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void Mouse::handleEvent(SDL_Event* e)
{
	// Gets mouse positon when one of these events occurs
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);	
	}
}

void Mouse::render()
{
	// TODO
	return;
}

