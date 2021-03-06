#pragma once
#include "Render.hpp"
#include "TextureManager.h"
#include <utility>


class Cell;
class Team;

class Player
{
protected:

	int speed_;
	bool canmove;
	bool active_;
	bool done_;
	int health;
	Team* team_;
	SDL_Texture* playerTex;
	SDL_Rect srcRect, destRect;
    Cell* cell_;

public:
	Player();
	Player(const char*, int, int);

	string type;
	void update();
	void render();
	void render(SDL_Rect src, SDL_Rect dest);
	void cell(Cell*);
	Cell* cell();
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
	Team* team();
	int xpos;
	int ypos;
};

class Rock : public Player
{
public:
	const string type = "rock";
	Rock(Team* team);
};

class Paper : public Player
{
public:
	const string type = "paper";
	Paper(Team* team);
};

class Scissors : public Player
{
public:
	const string type = "scissors";
	Scissors(Team* team);
};