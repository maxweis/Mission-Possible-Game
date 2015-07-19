#include "collision.h"

Direction CollisionSide(SDL_Rect *a, SDL_Rect *b)
{
        Direction dir = NONE;
        if (a->y >= b->y + (b->h / 2))
                dir = NORTH;

        if (a->x >= b->x){
                if (dir)
                        dir = mean(dir, EAST);
                else
                        dir = EAST;
        }

        if (a->y <= b->y - (b->h / 2)){
                if (dir)
                        dir = mean(dir, SOUTH);
                else
                        dir = SOUTH;
        }

        if (a->x <= b->x){
                if (dir)
                        dir = mean(dir, WEST);
                else
                        dir = WEST;
        }

        return dir;
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
        Direction dir = NONE;
        if (a->y - border <= b->y && a->y >= b->y)
                dir = NORTH;

        if (a->x + a->w + border >= b->x + b->w && a->x + a->w <= b->x + b->w){
                if (dir)
                        dir = mean(dir, EAST);
                else
                        dir = EAST;
                }

        if (a->y + a->h + border >= b->y + b->h && a->y + a->h <= b->y + b->h){
                if (dir)
                        dir = mean(dir, SOUTH);
                else
                        dir = SOUTH;
        }

        if (a->x - border <= b->x && a->x >= b->x){
                if (dir)
                        dir = mean(dir, WEST);
                else
                        dir = WEST;
        }

        return dir;
}

Direction ViewCollision(SDL_Rect *a, int view_length)
{
        SDL_Rect view = {SWIDTH / 2 - view_length / 2, 
                SHEIGHT / 2 - view_length / 2, view_length, view_length};

        return !(Collision(a, &view));
}

Direction ScreenCollision(SDL_Rect *a, int border)
{
        SDL_Rect screen = {0, 0, 1366, 768};

        return BorderCollision(a, &screen, border);
}

void BoundUpdate(Sprite *sprite) //fix w and h after rotation
{
}

bool ObjectsCollision(SDL_Rect *rect)
{
        for (int i = 0; i < object_number; i++)
                if (objects[i].solid && 
                                Collision(objects[i].sprite->rect, rect) != NONE)
                        return true;
        return false;
}

