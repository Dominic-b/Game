#include "stdafx.h"

bool Collision::pointVsRect(int x, int y, SDL_Rect a) {
	if (x >= a.x && x <= a.x + a.w && y >= a.y && y <= a.y + a.h) return true;
	return false;
}