#pragma once
#include "stdafx.h"

static class Levels {
public:

	static const int LEVEL_WIDTH = SCREEN_WIDTH;
	static const int LEVEL_HEIGHT = SCREEN_HEIGHT;

	static const int tileSize = 16;
	int level[(LEVEL_WIDTH / tileSize)][(LEVEL_HEIGHT / tileSize)];

	void textureInit(SDL_Renderer* renderer);
	void levelInit(std::string file);

	void drawTiles(SDL_Renderer* renderer);

	//tile with all sides having collision
	SDL_Texture* all;//1
	//top and left
	SDL_Texture* topLeft;//2
	//top
	SDL_Texture* top;//3
	SDL_Texture* topStickOut;//4
	//top and right
	SDL_Texture* topRight;//5
	//right
	SDL_Texture* right;//6
	SDL_Texture* rightStickOut;//7
	//bottom and right
	SDL_Texture* bottomRight;//8
	//bottom
	SDL_Texture* bottom;//9
	SDL_Texture* bottomStickOut;//10
	//bottom and left
	SDL_Texture* bottomLeft;//11
	//left
	SDL_Texture* left;//12
	SDL_Texture* leftStickOut;//13
	//none
	SDL_Texture* center;//14
	//left and right
	SDL_Texture* leftRight;//15
	//top and bottom
	SDL_Texture* topBottom;//16
};