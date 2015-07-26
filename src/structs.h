#pragma once

#include "enums.h"

typedef struct Vector{
        double x;
        double y;
} Vector;

typedef struct Sprite{
        int frame;
        double angle;
        double temp_angle;
        int scale;
        SDL_Texture *image;
        SDL_Rect *rect;
} Sprite;

typedef struct Object{
        Sprite *sprite;

        bool solid;

        Vector vel;

        Direction move;

        Direction collision;

        SDL_Rect *temp_rect;

        Vector dimensions;

        int id;
} Object;

typedef struct Player{
        Object *object;

        int health;
        int attack;
        int defense;

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

