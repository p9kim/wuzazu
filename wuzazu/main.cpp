#include <iostream>
#include "SDL.h"
#include "Game.hpp"
#include "Render.hpp"
using namespace std;

Game *game = nullptr;

Render* renderer = new Render();

int main(int argc, char * argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	renderer->createWindow("Wuzazu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1050, 1050, true);
	
	game = new Game();
	game->init();

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	renderer->clean();
	
	return 0;
}
