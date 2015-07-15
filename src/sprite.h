#pragma once
#include "defs.h"

#include <SDL2/SDL_image.h>

extern SDL_Renderer *render;

Sprite *SpriteInit(int width, int height, int scale, const char *image_path); //add width or height as IDK (0) to use image size
