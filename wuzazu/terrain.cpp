#include "terrain.hpp"

void Terrain::draw(SDL_Rect src, SDL_Rect dest)
{
	TextureManager::Draw((SDL_Texture*)texture, src, dest);
}
bool Terrain::movement()
{
	return true;
}