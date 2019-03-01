#include "PlayerTypes.hpp"

Paper::Paper(const char* model)
{
	playerTex = TextureManager::LoadTexture(model);

	xpos = 0;
	ypos = 0;
	speed_ = 3;
	canmove = active_ = false;
}

Paper::Paper(const char* model, int x, int y)
{
	playerTex = TextureManager::LoadTexture(model);
	
	xpos = x;
	ypos = y;
	speed_ = 3;
	canmove = active_ = false;
}