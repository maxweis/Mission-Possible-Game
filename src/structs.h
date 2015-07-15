#pragma once

#include "enums.h"

typedef struct Vector{
        int x;
        int y;
} Vector;

typedef struct Sprite{
        int frame;
        double angle;
        double temp_angle;
        int scale;
        SDL_Texture *image;
        SDL_Rect *rect;

        void (*destroy)(void *self);
} Sprite;

typedef struct Object{
        Sprite *sprite;

        bool solid;

        Vector vel;

        Direction move;

        SDL_Rect *temp_rect;

        Vector dimensions;

        int id;
} Object;

typedef struct Player{
        Object *object;

        bool run;
} Player;

typedef struct Map{
        SDL_Rect *rect;
        Vector tiles;
} Map;

typedef struct View{
        SDL_Rect *rect;
        Vector offset;
} View;

