#include "Render.hpp"
#include <iostream>
#include "SDL.h"
#include "Game.hpp"
#include "TextureManager.h"

using namespace std;

Game *game = nullptr;
Render* renderer = new Render("Wuzazu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 53*42, 34*42, true);

int main(int argc, char * argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	
	game = new Game();

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		
		game->update();
		game->render();
		game->handleEvents();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	renderer->clean();
	
	return 0;
}
