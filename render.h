#pragma once
#include "stdafx.h"

class Render {
public:
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);

	void render(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);

	SDL_Rect rect;
};