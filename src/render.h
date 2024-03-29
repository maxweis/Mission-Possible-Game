#pragma once
#include "defs.h"

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <string.h>

extern Player *player;
extern SDL_Renderer *render;
extern char *object_list[];
extern char *background_list[];
extern int level_background;
extern Object objects[];
extern Vector mouse_pos;
extern int object_number;
extern int menu_selection;

void GameScreenRender();
void StartMenuRender();
void TextRender(char *text, SDL_Rect box, char *font_name, SDL_Color color, int size, bool center_horizontal);
