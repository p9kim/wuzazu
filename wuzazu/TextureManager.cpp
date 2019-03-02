#include "TextureManager.h"
#include "Render.hpp"

void TextureManager::init()
{
	rock_texture_y = TextureManager::LoadTexture("assets/rock_y.png");
	paper_texture_y = TextureManager::LoadTexture("assets/paper_y.png");
	scissors_texture_y = TextureManager::LoadTexture("assets/scissors_y.png");
	rock_texture_b = TextureManager::LoadTexture("assets/rock_b.png");
	paper_texture_b = TextureManager::LoadTexture("assets/paper_b.png");
	scissors_texture_b = TextureManager::LoadTexture("assets/scissors_b.png");
}

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer->getRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(renderer->getRenderer(), tex, &src, &dest);
}