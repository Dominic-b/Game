#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#undef main

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

const int SCREEN_WIDTH = (1920 / 3);// *2; // accounting for scaling on personal device
const int SCREEN_HEIGHT = (1080 / 3);// *2;

#include "render.h"
static Render render;
#include "objects.h"
static Object object;
#include "event.h"
static Event event;
#include "collision.h"
static Collision collision;
#include "menu.h"
static Menu menu;
#include "levels.h"
static Levels levels;