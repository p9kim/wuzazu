#include "Render.hpp"

Render::Render(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Render created" << endl;
		}
	}
}
SDL_Renderer* Render::getRenderer()
{
	if (this == nullptr)
		return 0;
	return renderer;
}
void Render::setRenderer(SDL_Renderer* ren)
{
	renderer = ren;
}
void Render::clean()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
void Render::renderingLoop()
{}
void Render::RenderClear()
{
	SDL_RenderClear(renderer);
}

void Render::RenderPresent()
{
	SDL_RenderPresent(renderer);
}