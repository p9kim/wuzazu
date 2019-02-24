#pragma once
#include "SDL.h"
#include <iostream>
using namespace std;

static class Render
{
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
public:
	Render();
	void setRenderer(SDL_Renderer*);
	SDL_Renderer* getRenderer();
	void RenderClear();
	void RenderPresent();
	void clean();
	void renderingLoop();
	bool createWindow(const char*, int, int, int, int, bool);
} renderer;