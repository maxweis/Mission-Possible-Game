#include "render.h"

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

TTF_Font *mono_font = NULL;
void InitRenderText(char *font)
{
        if (TTF_Init())
                fprintf(stderr, "TTF_Init() failed (install sdl2_ttf) : %s\n", TTF_GetError());
        mono_font = TTF_OpenFont(font, 12);
        if (mono_font == NULL)
                fprintf(stderr, "Missing font: %s\n", TTF_GetError());
}

void RenderText(char *text, SDL_Rect box, char *font)
{
        if (mono_font == NULL)
                InitRenderText(font);

        SDL_Color white = {255, 255, 255};
        SDL_Surface *text_surface = TTF_RenderText_Solid(mono_font, text, white);

        SDL_Texture *present = SDL_CreateTextureFromSurface(render, text_surface);

        SDL_RenderCopy(render, present, NULL, &box);
}

SDL_Texture *background = NULL;
void InitRenderBackground(char *background_path)
{
        background = IMG_LoadTexture(render, background_path); 
}

void RenderBackground(char *background_path)
{
        SDL_Rect size = {0, 0, SWIDTH, SHEIGHT};

        if (background == NULL)
                InitRenderBackground(background_path);

        SDL_RenderCopy(render, background, NULL, &size);
}

void RenderScreen()
{
        SDL_RenderClear(render);

        RenderBackground(background_list[level_background]);
        RenderPlayer();
        RenderObject();
        RenderCursor();

        SDL_RenderPresent(render);
}
