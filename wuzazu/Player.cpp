#include "Player.hpp"
Player::Player()
{
	xpos = 0;
	ypos = 0;
	speed_ = 3;
	canmove = active_ = done_ = false;
}

Player::Player(const char* model, int x, int y)
{
	playerTex = textureManager.LoadTexture(model);

	xpos = x;
	ypos = y;
	speed_ = 3;
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
	if (done_ == true)
		SDL_SetTextureColorMod(playerTex, 150, 150, 150);
	else
		SDL_SetTextureColorMod(playerTex, 255, 255, 255);
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
bool Player::done()
{
	return done_;
}
void Player::done(bool done)
{
	done_ = done;
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
int Player::speed()
{
	return this->speed_;
}
Team* Player::team()
{
	return team_;
}