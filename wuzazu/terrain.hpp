#pragma once
#include "TextureManager.h"
#include "Render.hpp"
#include <iostream>

class Terrain
{
protected:
	SDL_Texture* texture;
	unsigned int movementcost;
public:
	std::string name;
	void draw(SDL_Rect, SDL_Rect);
	bool movement();
	unsigned int getMovementCost();
};

static class Water : public Terrain
{
public:
	Water() {
		texture = TextureManager::LoadTexture("assets/water.png");
		movementcost = 99;
	}
} water;

static class Dirt : public Terrain
{
public:
	Dirt() {
		texture = TextureManager::LoadTexture("assets/dirt.png");
		movementcost = 2;
	}
} dirt;

static class Grass : public Terrain
{
public:
	Grass() {
		texture = TextureManager::LoadTexture("assets/grass.png");
		movementcost = 1;
	};
} grass;
