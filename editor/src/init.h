#include "defs.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "object.h"
#include "event.h"

SDL_Window *window;
SDL_Renderer *render;

void InitSDL(char *caption);
