#pragma once
#include "Render.hpp"
#include "TextureManager.h"
#include <utility>

class Cell;

class Player
{
protected:
	int xpos;
	int ypos;
	int speed_;
	bool canmove;
	bool active_;
	bool done_;
	int health;
	char team_;
	SDL_Texture* playerTex;
	SDL_Rect srcRect, destRect;
    Cell* cell;

public:
	Player();
	Player(const char*, int, int);

	string type;
	void update();
	void render();
	void render(SDL_Rect src, SDL_Rect dest);
	void setCell(Cell*);
	void movePlayerBy(int, int);
	void highlight();
	void unhighlight();
	int speed();
	bool active();
	void active(bool);
	bool getCanMove();
	void setCanMove(bool);
	bool done();
	void done(bool);
	char team();
};

class Rock : public Player
{
public:
	const string type = "rock";
	Rock(char team);
};

class Paper : public Player
{
public:
	const string type = "paper";
	Paper(char team);
};

class Scissors : public Player
{
public:
	const string type = "scissors";
	Scissors(char team);
};