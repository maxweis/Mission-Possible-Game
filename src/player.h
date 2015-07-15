#pragma once
#include "defs.h"
#include <string.h>

#include "collision.h"
#include "event.h"
#include "math.h"
#include "object.h"
#include "sprite.h"

extern Player *player;
extern long buffer;
extern Object objects[];
extern int object_number;
extern View *view;
extern Vector mouse_pos;

Player *PlayerCreate();
void PlayerAnimate();
void PlayerMouseRotate();
void PlayerUpdate();
void PlayerMove(Direction dir);
