#include "enums.h"

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Vector{
        int x;
        int y;
} Vector;

typedef struct Sprite{
        double frame;
        double angle;
        double temp_angle;
        int scale;
        SDL_Texture *image;
        SDL_Rect *rect;
        double w, h;

        void (*destroy)(void *self);
} Sprite;

typedef struct Player{
        Sprite *sprite;

        SDL_Rect *temp;

        bool run;

        void (*move)(Direction player);
} Player;

typedef struct View{
        int x, y;
} View;

typedef struct Object{
        Sprite *sprite;

        bool solid;

        int id;

        Vector vel;
} Object;
#endif
