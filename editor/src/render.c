#include "render.h"

SDL_Texture *cursor = NULL;
void InitRenderCursor()
{
        cursor = IMG_LoadTexture(render, "../art/cursors/game.png");
}

Object *cursor_object = NULL;
void RenderCursor()
{
        if (cursor == NULL)
                InitRenderCursor();
        SDL_Rect mouse = {mouse_x - 15, mouse_y - 15, 31, 31};
        cursor_object = CreateObject(input_solid, mouse_x, mouse_y, IDK, IDK, input_scale, object_list[object_selection]);
        SDL_Rect sprite = {
                cursor_object->sprite->rect->x,
                cursor_object->sprite->rect->y,
                cursor_object->sprite->rect->w,
                cursor_object->sprite->rect->h
        };

        SDL_RenderCopy(render, cursor_object->sprite->image, NULL, &sprite);
        SDL_RenderCopy(render, cursor, NULL, &mouse); 
}

void RenderObject()
{
        if (render_object_number != 0){
                for (int i = 0; i < render_object_number; i++){
                        SDL_Rect sprite = {
                                render_objects[i].sprite->rect->x,
                                render_objects[i].sprite->rect->y,
                                render_objects[i].sprite->rect->w,
                                render_objects[i].sprite->rect->h
                        };

                        SDL_Rect slide = {
                                render_objects[i].sprite->rect->w / render_objects[i].sprite->scale * render_objects[i].sprite->frame,
                                0,
                                render_objects[i].sprite->rect->w / render_objects[i].sprite->scale,
                                render_objects[i].sprite->rect->h / render_objects[i].sprite->scale
                        };

                        SDL_RenderCopy(render, render_objects[i].sprite->image, &slide, &sprite);
                }
        }
}

TTF_Font *mono_font = NULL;
void InitRenderText(char *font)
{
        if (TTF_Init())
                fprintf(stderr, "TTF_Init() failed (install sdl2_ttf) : %s", TTF_GetError());
        mono_font = TTF_OpenFont(font, 12);
        if (mono_font == NULL)
                fprintf(stderr, "Missing font: %s", TTF_GetError());
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

void RenderCoords()
{
        char coords[64];

        sprintf(coords, "%d; %d, %d; %d", input_solid, mouse_x, mouse_y, input_scale);

        SDL_Rect box = {
                1266, 700,
                100, 68};

        RenderText(coords, box, "../art/fonts/UbuntuMono-R.ttf");
}

SDL_Texture *background = NULL;
void InitRenderBackground()
{
        background = IMG_LoadTexture(render, "../art/backgrounds/brick.jpg");
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
        RenderObject();
        RenderCursor();
        RenderCoords();

        SDL_RenderPresent(render);
}
