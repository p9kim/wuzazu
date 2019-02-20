#include "Player.hpp"

Player::Player(const char* model)
{
	playerTex = TextureManager::LoadTexture(model);

	xpos = 0;
	ypos = 0;
}

Player::Player(const char* model, int x, int y)
{
	playerTex = TextureManager::LoadTexture(model);

	xpos = x;
	ypos = y;
}

void Player::update()
{
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void Player::render()
{
	SDL_RenderCopy(Game::renderer, playerTex, &srcRect, &destRect);
}
void Player::render(SDL_Rect src, SDL_Rect dest)
{
	srcRect = src;
	destRect = dest;
	SDL_RenderCopy(Game::renderer, playerTex, &srcRect, &destRect);
}

void Player::movePlayerBy(int x, int y)
{
	this->xpos += x;
	this->ypos += y;
}

void Player::moveTo(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
}
void Player::setCell(Cell* c)
{
	cell = c;
}
void Player::setCoord(std::pair<unsigned int, unsigned int> coord)
{
	xpos = coord.first;
	ypos = coord.second;

}