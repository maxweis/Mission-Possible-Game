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
        if (render_object_number != 0){
                for (int i = 0; i < render_object_number; i++){
                        SDL_Rect sprite = {render_objects[i].sprite->rect->x,
                                render_objects[i].sprite->rect->y,
                                render_objects[i].sprite->rect->w,
                                render_objects[i].sprite->rect->h};

                        SDL_Rect slide = {render_objects[i].sprite->rect->w / render_objects[i].sprite->scale * render_objects[i].sprite->frame,
                                0,
                                render_objects[i].sprite->rect->w / render_objects[i].sprite->scale,
                                render_objects[i].sprite->rect->h / render_objects[i].sprite->scale};

                        SDL_RenderCopy(render, render_objects[i].sprite->image, &slide, &sprite);
                }
        }
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
