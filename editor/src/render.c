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
        SDL_Rect mouse = {mouse_pos.x - 15, mouse_pos.y - 15, 31, 31};
        cursor_object = CreateObject(input_solid, mouse_pos.x, mouse_pos.y, IDK, IDK, input_scale, object_selection, input_angle);
        SDL_Rect sprite = {
                cursor_object->sprite->rect->x,
                cursor_object->sprite->rect->y,
                cursor_object->sprite->rect->w,
                cursor_object->sprite->rect->h
        };

        SDL_RenderCopyEx(render, cursor_object->sprite->image, NULL, &sprite, input_angle, NULL, SDL_FLIP_NONE);
        SDL_RenderCopy(render, cursor, NULL, &mouse); 
}

void RenderObject()
{
        if (render_object_number > 0){
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

                        SDL_RenderCopyEx(render, render_objects[i].sprite->image, &slide, &sprite, render_objects[i].sprite->angle, NULL, SDL_FLIP_NONE);
                }
        }
}

TTF_Font *mono_font = NULL;
void InitRenderText(char *font)
{
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

void RenderCoords()
{
        char coords[64];

        sprintf(coords, "%d; %d, %d; %d; %d", input_solid, mouse_pos.x, mouse_pos.y, input_scale, input_angle);

        SDL_Rect box = {
                1266, 700,
                100, 68};

        RenderText(coords, box, "../art/fonts/UbuntuMono-R.ttf");
}

SDL_Texture *background = NULL;
void InitRenderBackground(char *background_path)
{
        background = IMG_LoadTexture(render, background_path);
        if (background == NULL)
                fprintf(stderr, "Image not loaded : %s\n", SDL_GetError());
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
        RenderObject();
        RenderCursor();
        RenderCoords();

        SDL_RenderPresent(render);
}
