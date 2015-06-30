#include "defs.h"

Direction Collision(SDL_Rect *a, SDL_Rect *b);
Direction ScreenCollision(SDL_Rect *a, int border);
Direction BorderCollision(SDL_Rect *a, SDL_Rect *b, int border);
void UpdateBound(Sprite *sprite);
