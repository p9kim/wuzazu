#include <iostream>

#include "Map.hpp"
#include "Game.hpp"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.hpp"
#include "MouseButtons.hpp"

// Don't need will delete later
#include "ECS.hpp"
#include "Components.hpp"

using namespace std;

SDL_Texture* playerTex;
SDL_Rect srcR, destR;
Player* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	isRunning = false;
	int flags = 0;
	renders = 0;
	if (fullscreen)
	{
		int flag = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL initialization success" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			cout << "Window created!" << endl;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Render created" << endl;
		}
	
		isRunning = true;
	}
	
	//playerTex = TextureManager::LoadTexture("assets/eggman.png", renderer);
	player = new Player("assets/testPlayer.png", 500, 500);
	//enemy = new GameObject("assets/testPlayer.png", 50, 50);
	map = new Map();

	//newPlayer.addComponent<PositionComponent>();
	//newPlayer.getComponent<PositionComponent>().setPos(500, 500);
}
void Game::handleEvents()
{
	SDL_Event e;
	/*
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type = SDL_QUIT)
		{
			isRunning = false;
		}
	}
	*/
	int moveby = 24;
	SDL_PollEvent(&e);
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		player->movePlayerBy(0, -(moveby));
		std::cout << "UP" << std::endl;
		break;
	case SDLK_DOWN:
		player->movePlayerBy(0, moveby);
		std::cout << "DOWN" << std::endl;
		break;
	case SDLK_LEFT:
		player->movePlayerBy(-(moveby), 0);
		std::cout << "LEFT" << std::endl;
		break;
	case SDLK_RIGHT:
		player->movePlayerBy(moveby, 0);
		std::cout << "RIGHT" << std::endl;
		break;
	default:
		break;
	}
	switch (e.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	
}
void Game::update()
{
	player->update();
	//enemy->Update();
	manager.update();
	/*std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << std::endl;*/
}
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->render();
	//enemy->Render();
	SDL_RenderPresent(renderer);
	renders++;
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
bool Game::running()
{
	return isRunning;
}