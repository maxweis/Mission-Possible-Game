#include "collision.h"

DIRECTION CollisionSide(SDL_Rect *a, SDL_Rect *b)
{
        if (a->y <= b->y - (b->h / 2))
                return DOWN;
        if (a->y >= b->y + (b->h / 2))
                return UP;
        if (a->x < b->x)
                return LEFT;
        if (a->x > b->x)
                return RIGHT;
        return NONE;
}

DIRECTION ScreenCollision(SDL_Rect *a)
{
        if (a->y < 0)
                return UP;
        if (a->x + a->w > SWIDTH)
                return RIGHT;
        if (a->y + a->h > SHEIGHT)
                return DOWN;
        if (a->x < 0)
                return LEFT;
        return NONE;
}

DIRECTION Collision(SDL_Rect *a, SDL_Rect *b)
{
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        leftA = a->x;
        rightA = a->x + a->w;
        topA = a->y;
        bottomA = a->y + a->h;

        leftB = b->x;
        rightB = b->x + b->w;
        topB = b->y;
        bottomB = b->y + b->h;

        if (bottomA <= topB ||
                        topA >= bottomB ||
                        rightA <= leftB ||
                        leftA >= rightB)
                return NONE;
        else
                return CollisionSide(a, b);
}

void UpdateBound(Sprite *sprite) //fix w and h after rotation
{
}
