#include "render.h"

#include <SDL2/SDL_image.h>

void RenderScreen()
{
        SDL_RenderClear(render);
        SDL_Rect rect = {player->sprite->rect->x, player->sprite->rect->y, 57, 42};
        SDL_Rect rectangle = {player->sprite->rect->w * player->sprite->frame, 0, 19, 14};
        SDL_RenderCopyEx(render, player->sprite->image, &rectangle, &rect, player->sprite->angle, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(render);
}
