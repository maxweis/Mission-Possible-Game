#include "defs.h"

#include <string.h>
#include <math.h>

#include "sprite.h"
#include "event.h"

extern Player *player;
extern long buffer;

Player *CreatePlayer();
void PlayerAnimate();
void PlayerMouseRotate();
void PlayerUpdate();
