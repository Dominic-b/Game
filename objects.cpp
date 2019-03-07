#include "stdafx.h"

Object::Camera::Camera() {
	x = 0;
	y = 0;
}

void Object::moveCamera(Camera &camera, Player player) {
	//moving the camera to center on the player
	camera.x = (player.x + player.w / 2) - SCREEN_WIDTH / 2;
	camera.y = (player.y + player.h / 2) - SCREEN_HEIGHT / 2;
}

Object::Player::Player() {
	x = 0;
	y = 0;
	velX = 0;
	velY = 0;

	w = 16;
	h = 16;

	player.x = 0;
	player.y = 0;
	player.w = w;
	player.h = h;
}

void Object::movePlayer(Player &player) {
	//moving the position by the velocity
	player.x += player.velX;
	player.y += player.velY;
}

void Object::drawPlayer(Player &player, Camera &camera, SDL_Renderer* renderer) {
	player.player.x = player.x - camera.x;
	player.player.y = player.y - camera.y;

	SDL_SetRenderDrawColor(renderer, 150, 150, 150, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &player.player);
}