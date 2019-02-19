#pragma once
#include "TextureManager.h"
#include <iostream>

class Terrain
{
protected:
	SDL_Texture* texture;
public:
	std::string name;
	void draw(SDL_Rect, SDL_Rect);
	bool movement();
};

static class Water : public Terrain
{
public:
	Water() {
		texture = TextureManager::LoadTexture("assets/water.png");
	}
} water;

static class Dirt : public Terrain
{
public:
	Dirt() {
		texture = TextureManager::LoadTexture("assets/dirt.png");
	}
} dirt;

static class Grass : public Terrain
{
public:
	Grass() {
		texture = TextureManager::LoadTexture("assets/grass.png");
	};
} grass;
