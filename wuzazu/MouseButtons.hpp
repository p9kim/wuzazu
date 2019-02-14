#pragma once
#include "Game.hpp"
#include "Player.hpp"

const int BUTTON_WIDTH = 5;
const int BUTTON_HEIGHT = 5;
const int TOTAL_BUTTONS = 1;

enum clickSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class Mouse
{
public:
	Mouse();

	void setPosition(int, int);
	void handleEvent(SDL_Event*);
	void render();

private:
	SDL_Point mPosition;
	clickSprite mCurrSprite;
};