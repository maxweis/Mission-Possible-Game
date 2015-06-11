#include "defs.h"

#include <string.h>
#include <math.h>

#include "sprite.h"
#include "collision.h"
#include "event.h"
#include "object.h"

extern Player *player;
extern long buffer;
extern SDL_Rect screen;
extern int mouse_x, mouse_y;
extern Object objects[];
extern int object_number;

Player *CreatePlayer();
void PlayerAnimate();
void PlayerMouseRotate();
void PlayerUpdate();
