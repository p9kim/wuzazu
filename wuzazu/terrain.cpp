#include "terrain.hpp"

bool Terrain::draw(SDL_Rect src, SDL_Rect dest)
{
	if(getImageFile() == NULL)
	{
		std::cerr << "Exception while drawing terrain" << std::endl;
		return false;
	}
	TextureManager::Draw(TextureManager::LoadTexture(getImageFile()), src, dest);
	return true;
}
bool Terrain::movement()
{
	return true;
}