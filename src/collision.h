#include "defs.h"

Direction Collision(SDL_Rect *a, SDL_Rect *b);
Direction ScreenCollision(SDL_Rect *a, int border);
void UpdateBound(Sprite *sprite);
