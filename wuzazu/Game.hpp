#pragma once
#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.hpp"
#include "MouseButtons.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

class Game
{
protected:

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Renderer *renderer;

private:
	int renders = 0;
	bool isRunning;
	SDL_Window *window;

};
#endif

