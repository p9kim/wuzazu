#pragma once
#include "Game.hpp"

static class TextureManager
{
public: 
	SDL_Texture* rock_texture_y;
	SDL_Texture* paper_texture_y;
	SDL_Texture* scissors_texture_y;
	SDL_Texture* rock_texture_b;
	SDL_Texture* paper_texture_b;
	SDL_Texture* scissors_texture_b;
	void init();
	SDL_Texture* LoadTexture(const char* fileName);
	void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

	//SDL_Texture* gTexture = NULL;

private:
} textureManager;