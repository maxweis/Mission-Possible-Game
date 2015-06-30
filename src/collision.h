#include "defs.h"

Direction Collision(SDL_Rect *a, SDL_Rect *b);
Direction ScreenCollision(SDL_Rect *a, int border);
Direction BorderCollision(SDL_Rect *a, SDL_Rect *b, int border);
Direction ViewCollision(SDL_Rect *a, int view_length);
void UpdateBound(Sprite *sprite);
