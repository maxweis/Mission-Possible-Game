#pragma once
#include "defs.h"

#include "maths.h"
#include "object.h"

Direction Collision(SDL_Rect *a, SDL_Rect *b);
Direction ScreenCollision(SDL_Rect *a, int border);
Direction BorderCollision(SDL_Rect *a, SDL_Rect *b, int border);
Direction ViewCollision(SDL_Rect *a, int view_length);
void BoundUpdate(Sprite *sprite);
bool ObjectsCollision(SDL_Rect *rect);
