#pragma once
#include "TextureManager.h"
#include "Pixel.hpp"
#include <iostream>

class Terrain
{
private:
	const char* imageFile;
protected:
public:
	virtual const char* getImageFile() = 0;
	bool draw(SDL_Rect, SDL_Rect);
	bool movement();
};

class Water : public Terrain
{
public:
	const char* getImageFile() { return "assets/water.png"; }
};

class Dirt : public Terrain
{
public:
	const char* getImageFile() { return "assets/dirt.png"; }
};

class Grass : public Terrain
{
public:
	const char* getImageFile() { return "assets/grass.png"; }
};
