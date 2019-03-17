#pragma once
#include "SDL.h"
#include "Pixel.hpp"
#include <iostream>
using namespace std;

class Render
{
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
public:
	Render(const char*, int, int, int, int, bool);
	void setRenderer(SDL_Renderer*);
	SDL_Renderer* getRenderer();
	void RenderClear();
	void RenderPresent();
	void clean();
	void renderingLoop();
	void updateCamera(unsigned int x, unsigned int y);
	SDL_Rect camera = { 0, 0, 850, 850 };
	void fillSquare(int x, int y, Pixel color);
};

extern Render* renderer;