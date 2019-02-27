#include "Player.hpp"

Player::Player(const char* model)
{
	playerTex = TextureManager::LoadTexture(model);

	xpos = 0;
	ypos = 0;
	movementpts = 3;
	canmove = active_ = false;
}

Player::Player(const char* model, int x, int y)
{
	playerTex = TextureManager::LoadTexture(model);

	xpos = x;
	ypos = y;
	movementpts = 3;
	canmove = false;
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
	SDL_RenderCopy(renderer->getRenderer(), playerTex, &srcRect, &destRect);
}
void Player::render(SDL_Rect src, SDL_Rect dest)
{
	srcRect = src;
	destRect = dest;
	SDL_RenderCopy(renderer->getRenderer(), playerTex, &srcRect, &destRect);
}

void Player::movePlayerBy(int x, int y)
{
	this->xpos += x;
	this->ypos += y;
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
void Player::highlight()
{
	SDL_SetTextureColorMod(playerTex, -255, 255, 255);
}
void Player::unhighlight()
{
	SDL_SetTextureColorMod(playerTex, 255, 255, 255);
}
bool Player::getCanMove()
{
	return canmove;
}
void Player::setCanMove(bool canmove)
{
	this->canmove = canmove;
}
bool Player::active()
{
	if (this == nullptr)
		return false;
	return this->active_;
}
void Player::active(bool active)
{
	this->active_ = active;
}