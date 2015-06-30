#include "defs.h"

#include <SDL2/SDL_ttf.h>

#include "event.h"
#include "object.h"
#include "player.h"

void InitSDL(char *caption);

SDL_Window *window;
SDL_Renderer *render;
View *view;
