#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "structs.h"
#include "enums.h"

#define SWIDTH 1920
#define SHEIGHT 1080
#define IDK 0
#define OBJECT_LIMIT 1000

SDL_Window *window;
SDL_Renderer *render;
Map *map;
Player *player;
bool done;
