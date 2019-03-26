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
	SDL_Rect camera = { 0, 0, 1050, 1050 };
	SDL_Rect winBox_ = { 0, 0, 1050, 1050 };

public:
	Render(const char*, int, int, int, int, bool);
	~Render();
	void setRenderer(SDL_Renderer*);
	SDL_Renderer* getRenderer();
	void RenderClear();
	void RenderPresent();
	void renderingLoop();
	void updateCamera(unsigned int x, unsigned int y);
	void updateCameraBy(int x, int y);
	SDL_Rect getCamera();
	void fillSquare(int x, int y, Pixel color);
	SDL_Rect winBox();
};

extern Render* renderer;