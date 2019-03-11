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
	teams_ = *(new vector<char>(0));
	players = *(new vector<Player*>(0));
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
	switch (e.type)
	{
	case SDL_KEYDOWN:
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
		case SDLK_SPACE:
			switchTurn();
			break;
		default:
			break;
		}
		break;
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
	player->update(); //dummy character
}
void Game::render()
{
	renderer->RenderClear();
	map->DrawMap();
	renderer->updateCamera(player->xpos, player->ypos);
	player->render();
	renderer->renderingLoop();
	renderer->RenderPresent();
}
void Game::switchTurn()
{
	currentTeam_ = teams_.at(turn_ % teams_.size());
	for (Player* p : players)
		p->done(false);
	turn_++;
	cout << "Turn: " << currentTeam_ << endl;
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
unsigned int Game::turn() 
{
	return turn_;
}
void Game::turn(unsigned int turn)
{
	turn_ = turn;
}
char Game::currentTeam()
{
	return currentTeam_;
}