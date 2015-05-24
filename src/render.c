#include "render.h"

#include <SDL2/SDL_image.h>

void RenderCursor()
{
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_Rect mouse = {x - 15, y - 15, 31, 31};
        SDL_Texture *cursor = IMG_LoadTexture(render, "art/cursors/game.png");
        SDL_RenderCopy(render, cursor, NULL, &mouse); 
}

void RenderPlayer()
{
        SDL_Rect sprite = {player->sprite->rect->x, player->sprite->rect->y, 57, 42};
        SDL_Rect slide = {player->sprite->rect->w * player->sprite->frame, 0, 19, 14};
        SDL_RenderCopyEx(render, player->sprite->image, &slide, &sprite, player->sprite->angle, NULL, SDL_FLIP_NONE);
}

void RenderBackground()
{
        SDL_Texture *background = IMG_LoadTexture(render, "art/backgrounds/brick.jpg");
        SDL_Rect size = {0, 0, SWIDTH, SHEIGHT};
        SDL_RenderCopy(render, background, NULL, &size);
}

void RenderScreen()
{
        SDL_RenderClear(render);

        /*RenderBackground();*/
        RenderPlayer();
        /*RenderCursor();*/

        SDL_RenderPresent(render);
}
