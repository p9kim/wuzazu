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
		//camera.x = {};
		//camera.y = {};
	}
	SDL_SetRenderDrawBlendMode(getRenderer(), SDL_BLENDMODE_BLEND);
}
void Render::updateCamera(unsigned int x, unsigned int y)
{
	camera.x = (x/2)-(1050/2);
	camera.y = (y / 2) - (1050 / 2);
	if (camera.x < 0)
		camera.x = 0;
	if (camera.y < 0)
		camera.y = 0;
	if (camera.x > 53 * 42 - camera.w) //map width - camera.w
		camera.x = 53 * 42 - camera.w;
	if (camera.y > 34*42 - camera.h) //map.heigh - camera.h
		camera.y = 34*42 - camera.h;
	cout << "x:"<< camera.x << " w:" << camera.w << " y:" << camera.y << " h:" << camera.h << endl;
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
void Render::renderingLoop()
{

}
void Render::RenderClear()
{
	SDL_RenderClear(renderer);
}

void Render::RenderPresent()
{
	SDL_RenderPresent(renderer);
}

void Render::fillSquare(int x, int y, Pixel color)
{
	SDL_SetRenderDrawColor(renderer, color.R(), color.G(), color.B(), 80);
	SDL_Rect square = { x*42, y*42, x*42 + 42, y*42 + 42 };
	SDL_RenderFillRect(renderer, &square);
}

SDL_Rect Render::getCamera()
{
	return camera;
}

Render::~Render()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}