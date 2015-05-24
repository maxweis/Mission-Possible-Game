#include "enums.h"

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Sprite {
        int frame;
        double angle;
        SDL_Texture *image;
        SDL_Rect *rect;

        void (*destroy)(void *self);
} Sprite;

typedef struct Player{
        Sprite *sprite;

        bool run;

        void (*move)(DIRECTION player);
        void (*update)();
} Player;

#endif
