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
	unsigned int weight();
};

static class Water : public Terrain
{
public:
	Water() {
		texture = textureManager.LoadTexture("assets/water.png");
		movementcost = 99;
	}
} water;

static class Mountain : public Terrain
{
public:
	Mountain() {
		texture = textureManager.LoadTexture("assets/mountain.png");
		movementcost = 3;
	}
} mountain;

static class Grass : public Terrain
{
public:
	Grass() {
		texture = textureManager.LoadTexture("assets/grass.png");
		movementcost = 1;
	};
} grass;

static class Forest : public Terrain
{
public:
	Forest() {
		texture = textureManager.LoadTexture("assets/tree.png");
		movementcost = 2;
	};
} forest;

static class Village : public Terrain
{
public:
	Village() {
		texture = textureManager.LoadTexture("assets/village.png");
		movementcost = 1;
	};
} village;

static class Ore : public Terrain
{
public:
	Ore() {
		texture = textureManager.LoadTexture("assets/ore.png");
		movementcost = 1;
	};
} ore;
