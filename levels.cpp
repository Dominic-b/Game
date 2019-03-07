#include "stdafx.h"

void Levels::textureInit(SDL_Renderer* renderer) {
	all = render.loadTexture("Assets/Images/tileTextures/test1/single.png", renderer);
	topLeft = render.loadTexture("Assets/Images/tileTextures/test1/topLeft.png", renderer);
	top = render.loadTexture("Assets/Images/tileTextures/test1/top.png", renderer);
	topStickOut = render.loadTexture("Assets/Images/tileTextures/test1/topStickOut.png", renderer);
	topRight = render.loadTexture("Assets/Images/tileTextures/test1/topRight.png", renderer);
	right = render.loadTexture("Assets/Images/tileTextures/test1/right.png", renderer);
	rightStickOut = render.loadTexture("Assets/Images/tileTextures/test1/rightStickOut.png", renderer);
	bottomRight = render.loadTexture("Assets/Images/tileTextures/test1/bottomRight.png", renderer);
	bottom = render.loadTexture("Assets/Images/tileTextures/test1/bottom.png", renderer);
	bottomStickOut = render.loadTexture("Assets/Images/tileTextures/test1/bottomStickOut.png", renderer);
	bottomLeft = render.loadTexture("Assets/Images/tileTextures/test1/bottomLeft.png", renderer);
	left = render.loadTexture("Assets/Images/tileTextures/test1/left.png", renderer);
	leftStickOut = render.loadTexture("Assets/Images/tileTextures/test1/leftStickOut.png", renderer);
	center = render.loadTexture("Assets/Images/tileTextures/test1/center.png", renderer);
	leftRight = render.loadTexture("Assets/Images/tileTextures/test1/wall.png", renderer);
	topBottom = render.loadTexture("Assets/Images/tileTextures/test1/ceiling.png", renderer);
}

void Levels::levelInit(std::string file) {
	std::ifstream myfile;
	myfile.open(file);
	if (myfile.is_open()) {
		for (int i = 0; i < LEVEL_HEIGHT / tileSize; i++) {
			for (int j = 0; j < LEVEL_WIDTH / tileSize; j++) {
				myfile >> level[j][i];
			}
		}
	} else {
		printf("wrong file name there bucko");
	}
	myfile.close();

	for (int i = 0; i < LEVEL_WIDTH / tileSize; i++) {//sorting tiles
		for (int j = 0; j < LEVEL_HEIGHT / tileSize; j++) {
			if (level[i][j] != 0) {//checks if it is a tile or not
				//                      Right                    Left                   Bottom                   Top
				if (level[i + 1][j] == 0 && level[i - 1][j] == 0 && level[i][j + 1] == 0 && level[i][j - 1] == 0) level[i][j] = 1;//all
				else if (level[i + 1][j] != 0 && level[i - 1][j] == 0 && level[i][j + 1] != 0 && level[i][j - 1] == 0) level[i][j] = 2;//topleft
				else if (level[i + 1][j] != 0 && level[i - 1][j] != 0 && level[i][j + 1] != 0 && level[i][j - 1] == 0) level[i][j] = 3;//top
				else if (level[i + 1][j] == 0 && level[i - 1][j] == 0 && level[i][j + 1] != 0 && level[i][j - 1] == 0) level[i][j] = 4;//topstickout
				else if (level[i + 1][j] == 0 && level[i - 1][j] != 0 && level[i][j + 1] != 0 && level[i][j - 1] == 0) level[i][j] = 5;//topright
				else if (level[i + 1][j] == 0 && level[i - 1][j] != 0 && level[i][j + 1] != 0 && level[i][j - 1] != 0) level[i][j] = 6;//right
				else if (level[i + 1][j] == 0 && level[i - 1][j] != 0 && level[i][j + 1] == 0 && level[i][j - 1] == 0) level[i][j] = 7;//rightstickout
				else if (level[i + 1][j] == 0 && level[i - 1][j] != 0 && level[i][j + 1] == 0 && level[i][j - 1] != 0) level[i][j] = 8;//bottomright
				else if (level[i + 1][j] != 0 && level[i - 1][j] != 0 && level[i][j + 1] == 0 && level[i][j - 1] != 0) level[i][j] = 9;//bottom
				else if (level[i + 1][j] == 0 && level[i - 1][j] == 0 && level[i][j + 1] == 0 && level[i][j - 1] != 0) level[i][j] = 10;//bottomstickout
				else if (level[i + 1][j] == 0 && level[i - 1][j] != 0 && level[i][j + 1] == 0 && level[i][j - 1] != 0) level[i][j] = 11;//bottomleft
				else if (level[i + 1][j] != 0 && level[i - 1][j] == 0 && level[i][j + 1] != 0 && level[i][j - 1] != 0) level[i][j] = 12;//left
				else if (level[i + 1][j] != 0 && level[i - 1][j] == 0 && level[i][j + 1] == 0 && level[i][j - 1] == 0) level[i][j] = 13;//leftstickout
				else if (level[i + 1][j] != 0 && level[i - 1][j] != 0 && level[i][j + 1] != 0 && level[i][j - 1] != 0) level[i][j] = 14;//center
				else if (level[i + 1][j] == 0 && level[i - 1][j] == 0 && level[i][j + 1] != 0 && level[i][j - 1] != 0) level[i][j] = 15;//leftright
				else if (level[i + 1][j] != 0 && level[i - 1][j] != 0 && level[i][j + 1] == 0 && level[i][j - 1] == 0) level[i][j] = 16;//topbottom
			}
		}
	}
}

void Levels::drawTiles(SDL_Renderer* renderer) {
	for (int i = 0; i < LEVEL_WIDTH / tileSize; i++) {
		for (int j = 0; j < LEVEL_HEIGHT / tileSize; j++) {
			switch (level[i][j]) {
				case 1:
					render.render(renderer, all, (i * tileSize), (j * tileSize));
					break;
				case 2:
					render.render(renderer, topLeft, (i * tileSize), (j * tileSize));
					break;
				case 3:
					render.render(renderer, top, (i * tileSize), (j * tileSize));
					break;
				case 4:
					render.render(renderer, topStickOut, (i * tileSize), (j * tileSize));
					break;
				case 5:
					render.render(renderer, topRight, (i * tileSize), (j * tileSize));
					break;
				case 6:
					render.render(renderer, right, (i * tileSize), (j * tileSize));
					break;
				case 7:
					render.render(renderer, rightStickOut, (i * tileSize), (j * tileSize));
					break;
				case 8:
					render.render(renderer, bottomRight, (i * tileSize), (j * tileSize));
					break;
				case 9:
					render.render(renderer, bottom, (i * tileSize), (j * tileSize));
					break;
				case 10:
					render.render(renderer, bottomStickOut, (i * tileSize), (j * tileSize));
					break;
				case 11:
					render.render(renderer, bottomLeft, (i * tileSize), (j * tileSize));
					break;
				case 12:
					render.render(renderer, left, (i * tileSize), (j * tileSize));
					break;
				case 13:
					render.render(renderer, leftStickOut, (i * tileSize), (j * tileSize));
					break;
				case 14:
					render.render(renderer, center, (i * tileSize), (j * tileSize));
					break;
				case 15:
					render.render(renderer, leftRight, (i * tileSize), (j * tileSize));
					break;
				case 16:
					render.render(renderer, topBottom, (i * tileSize), (j * tileSize));
					break;
			}
		}
	}
}