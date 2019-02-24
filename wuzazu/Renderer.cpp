#include "Render.hpp"

Render::Render()
{
}
SDL_Renderer* Render::getRenderer()
{
	return this->renderer;
}
void Render::setRenderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
void Render::clean()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
void Render::renderingLoop()
{}
void Render::RenderClear()
{
	SDL_RenderClear(this->renderer);
}

void Render::RenderPresent()
{
	SDL_RenderPresent(this->renderer);
}

bool Render::createWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		int flag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL initialization success" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			cout << "Window created!" << endl;
		this->renderer = SDL_CreateRenderer(window, -1, 0);
		if (this->renderer)
		{
			SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
			cout << "Render created" << endl;
		}

		return true;
	}
	return false;
}