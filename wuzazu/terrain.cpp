#include "terrain.hpp"

Water::Water()
{
	Water::texture = TextureManager::LoadTexture("assets/water.png");
}
Grass::Grass()
{
	Grass::texture = TextureManager::LoadTexture("assets/grass.png");
}
Dirt::Dirt()
{
	Dirt::texture = TextureManager::LoadTexture("assets/dirt.png");
}
void Terrain::draw(SDL_Rect src, SDL_Rect dest)
{
	TextureManager::Draw((SDL_Texture*)texture, src, dest);
}
bool Terrain::movement()
{
	return true;
}