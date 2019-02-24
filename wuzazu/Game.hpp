#pragma once
#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.hpp"
#include "MouseButtons.hpp"
#include "Render.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

class Game
{
protected:

public:
	Game();
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	bool running();
	void setRenderer(Render*);
private:
	bool isRunning;
	Render* renderer;

};
#endif

