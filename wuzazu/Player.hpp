#pragma once
#include "Game.hpp"
#include "TextureManager.h"
#include <utility>

class Cell;

class Player
{
private:
	int xpos;
	int ypos;

	SDL_Texture* playerTex;
	SDL_Rect srcRect, destRect;
    Cell* cell;

public:
	Player(const char*);
	Player(const char*, int, int);
	~Player();

	void update();
	void render();
	void render(SDL_Rect src, SDL_Rect dest);
	void setCell(Cell*);
	void setCoord(std::pair<unsigned int, unsigned int>);
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

	void moveTo(int, int);

};