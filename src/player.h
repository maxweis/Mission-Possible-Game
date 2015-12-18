#pragma once
#include "defs.h"
#include <string.h>

#include "collision.h"
#include "event.h"
#include "math.h"
#include "object.h"
#include "sprite.h"
#include "render.h"

extern Player *player;
extern long buffer;
extern Object objects[];
extern int object_number;
extern Vector mouse_pos;

void PlayerInit();
Player *PlayerCreate();
void PlayerAnimate();
void PlayerMouseRotate();
void PlayerUpdate();
void PlayerMove(Direction dir);
void PlayerHealthAdd(int amount);
