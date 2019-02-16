#pragma once
#include "TextureManager.h"
#include "Pixel.hpp"
#include <iostream>

class Terrain
{
private:
	const char* imageFile;
protected:
	SDL_Texture* texture;
public:
	string name;
	void draw(SDL_Rect, SDL_Rect);
	bool movement();
};

class Water : public Terrain
{
public:
	Water();
};

class Dirt : public Terrain
{
public:
	Dirt();
};

class Grass : public Terrain
{
public:
	Grass();
};
