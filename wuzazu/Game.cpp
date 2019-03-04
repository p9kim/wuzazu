#include "Game.hpp"
#include "Map.hpp"
#include "Render.hpp"

using namespace std;

SDL_Texture* playerTex;
SDL_Rect srcR, destR;
Player* player;
Map* map;

Game::Game()
{
	teams_ = *(new vector<char>());
	players = *(new vector<Player*>());
	isRunning = true;
	player = new Player("assets/testPlayer.png", 500, 500);
	map = new Map(this);
}
Game::~Game()
{}

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
	if (e.type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		map->handleClick(x, y);
	}

	
}
void Game::update()
{
	player->update();
	//enemy->Update();
	/*std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << std::endl;*/
}
void Game::render()
{
	renderer->RenderClear();
	map->DrawMap();
	player->render();
	renderer->renderingLoop();
	renderer->RenderPresent();
}
bool Game::running()
{
	return isRunning;
}

vector<char> Game::teams()
{
	return teams_;
}
void Game::addTeam(char team)
{
	for (char t : teams_)
		if (t == team)
			return;
	teams_.push_back(team);
}
void Game::addPlayer(Player* p)
{
	players.push_back(p);
}