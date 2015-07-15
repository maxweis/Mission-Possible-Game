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
        if (a->y - border <= b->y && a->y >= b->y)
                return UP;
        if (a->x + a->w + border >= b->x + b->w && a->x + a->w <= b->x + b->w)
                return RIGHT;
        if (a->y + a->h + border >= b->y + b->h && a->y + a->h <= b->y + b->h)
                return DOWN;
        if (a->x - border <= b->x && a->x >= b->x)
                return LEFT;
        return NONE;
}

Direction ViewCollision(SDL_Rect *a, int view_length)
{
        SDL_Rect view = {SWIDTH / 2, SHEIGHT /2, view_length, view_length};

        return BorderCollision(&view, a, 1366);
}
        

Direction ScreenCollision(SDL_Rect *a, int border)
{
        SDL_Rect screen = {0, 0, 1366, 768};

        return BorderCollision(a, &screen, border);
}

void UpdateBound(Sprite *sprite) //fix w and h after rotation
{
}
