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
	SDL_Texture* texture;
	string name;
	void draw(SDL_Rect, SDL_Rect);
	bool movement();
};

static class Water : public Terrain
{
public:
	Water();
} water;

static class Dirt : public Terrain
{
public:
	Dirt();
} dirt;

static class Grass : public Terrain
{
public:
	Grass();
} grass;
