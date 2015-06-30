#include "enums.h"

#ifndef STRUCTS_H
#define STRUCTS_H

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
        int w, h;

        void (*destroy)(void *self);
} Sprite;

typedef struct Player{
        Sprite *sprite;

        SDL_Rect *temp;

        bool run;

        void (*move)(Direction player);
} Player;

typedef struct View{
        Vector offset;
} View;

typedef struct Object{
        Sprite *sprite;

        bool solid;

        Vector vel;

        int id;
} Object;
#endif
