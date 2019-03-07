#include "stdafx.h"

SDL_Texture* Render::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

void Render::render(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
	//Render to screen
	rect.x = x;
	rect.y = y;
	rect.w = levels.tileSize;
	rect.h = rect.w;
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}