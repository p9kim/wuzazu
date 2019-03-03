#pragma once
#include "Game.hpp"

static class TextureManager
{
public: 
	SDL_Texture* LoadTexture(const char* fileName);
	void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

private:
} textureManager;