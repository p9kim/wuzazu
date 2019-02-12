#include "Game.hpp"
#include "TextureManager.h"
#include "GameObject.h"
#include <iostream>
#include "Map.hpp"

#include "ECS.hpp"
#include "Components.hpp"

using namespace std;

//SDL_Texture* playerTex;
//SDL_Rect srcR, destR;
GameObject* player;
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
	player = new GameObject("assets/beeboop.png", 0, 0);
	enemy = new GameObject("assets/teedo.png", 50, 50);
	map = new Map();

	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos(500, 500);
}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
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
	player->Update();
	enemy->Update();
	manager.update();
	/*std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << std::endl;*/
}
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
bool Game::running()
{
	return isRunning;
}