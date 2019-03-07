#pragma once
#include "stdafx.h"

static class Object {
public:
	static struct Camera {
		int x, y;//position

		Camera();
	};

	static struct Player {
		float x, y;//position
		float velX, velY;//velocities

		int w, h;//width and height

		SDL_Rect player;//for drawing it

		Player();
	};

	void moveCamera(Camera &camera, Player player);

	void movePlayer(Player &player);

	void drawPlayer(Player &player, Camera &camera, SDL_Renderer* renderer);
};