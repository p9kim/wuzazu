#pragma once
#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.hpp"
#include "MouseButtons.hpp"
#include "Render.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

class Player;

class Game
{
private:
	bool isRunning;
	vector<char> teams_;
	vector<Player*> players;
	char currentTeam_;
	unsigned int turn_ = 0;
protected:

public:
	Game();
	~Game();
	void handleEvents();
	void update();
	void render();
	bool running();
	void switchTurn();

	vector<char> teams();
	void addTeam(char);
	void addPlayer(Player*);
	unsigned int turn();
	void turn(unsigned int);
	char currentTeam();

};
#endif

