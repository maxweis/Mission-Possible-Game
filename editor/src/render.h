#include "defs.h"

#include <SDL2/SDL_ttf.h>

#include "object.h"
#include "event.h"

extern SDL_Renderer *render;
extern char *object_list[];
extern char *background_list[];
extern int level_background;

void RenderScreen();
