#include "render.h"

#include <SDL2/SDL_image.h>

SDL_Texture *cursor = NULL;
void InitRenderCursor()
{
        cursor = IMG_LoadTexture(render, "art/cursors/game.png");
}

void RenderCursor()
{
        if (cursor == NULL)
                InitRenderCursor();
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_Rect mouse = {x - 15, y - 15, 31, 31};
        SDL_RenderCopy(render, cursor, NULL, &mouse); 
}

void RenderPlayer()
{
        SDL_Rect sprite = {player->sprite->rect->x,
               player->sprite->rect->y,
               player->sprite->w,
               player->sprite->h};

        SDL_Rect slide = {player->sprite->w / player->sprite->scale * player->sprite->frame,
               0,
               player->sprite->w / player->sprite->scale,
               player->sprite->h / player->sprite->scale};

        SDL_RenderCopyEx(render, player->sprite->image, &slide, &sprite,
                        player->sprite->angle, NULL, SDL_FLIP_NONE);
}

void RenderObject()
{
        SDL_Rect sprite = {object->sprite->rect->x,
                object->sprite->rect->y,
                object->sprite->rect->w,
                object->sprite->rect->h};

        SDL_Rect slide = {object->sprite->rect->w / object->sprite->scale * object->sprite->frame,
                0,
                object->sprite->rect->w / object->sprite->scale,
                object->sprite->rect->h / object->sprite->scale};

        SDL_RenderCopy(render, object->sprite->image, &slide, &sprite);
}

SDL_Texture *background = NULL;
void InitRenderBackground()
{
        background = IMG_LoadTexture(render, "art/backgrounds/brick.jpg");
}

void RenderBackground()
{
        SDL_Rect size = {0, 0, SWIDTH, SHEIGHT};

        if (background == NULL)
                InitRenderBackground();
        SDL_RenderCopy(render, background, NULL, &size);
}

void RenderScreen()
{
        SDL_RenderClear(render);

        RenderBackground();
        RenderPlayer();
        RenderObject();
        RenderCursor();

        SDL_RenderPresent(render);
}
