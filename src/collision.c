#include "collision.h"

Direction CollisionSide(SDL_Rect *a, SDL_Rect *b)
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

Direction Collision(SDL_Rect *a, SDL_Rect *b)
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

Direction BorderCollision(SDL_Rect *a, SDL_Rect *b, int border)
{
        if ((a->x + border >= b->x && a->x - border <= b->x) || 
                        (a->y + border >= b->y && a->y - border <= b->y) ||
                        (a->x + a->w + border >= b->x && a->x + a->w - border <= b->x) ||
                        (a->y + a->h + border >= b->y && a->y + a->h - border <= b->y)
                        )
                return Collision(a, b);
        else
                return NONE;
}

Direction ScreenCollision(SDL_Rect *a, int border)
{
        SDL_Rect screen = {0, 0, 1333, 733};

        return BorderCollision(&screen, a, border);
}

void UpdateBound(Sprite *sprite) //fix w and h after rotation
{
}
