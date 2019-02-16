#pragma once
#include "Game.hpp"
#include "TextureManager.h"

class Player
{
protected:

public:
	Player(const char*, int, int);
	~Player();

	void update();
	void render();

	enum KeyPress
	{
		KEY_PRESS_SURFACE_DEFAULT,
		KEY_PRESS_SURFACE_UP,
		KEY_PRESS_SURFACE_DOWN,
		KEY_PRESS_SURFACE_LEFT,
		KEY_PRESS_SURFACE_RIGHT,
		KEY_PRESS_SURFACE_TOTAL
	};

	void movePlayerBy(int, int);

private:
	int xpos;
	int ypos;

	SDL_Texture* playerTex;
	SDL_Rect srcRect, destRect;
};