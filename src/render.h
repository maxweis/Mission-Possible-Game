#include "defs.h"

#include <SDL2/SDL_ttf.h>

#include "event.h"
#include "object.h"

extern Player *player;
extern SDL_Renderer *render;
extern char *object_list[];
extern char *background_list[];
extern int level_background;

void RenderScreen();
