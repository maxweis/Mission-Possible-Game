#pragma once
#include "defs.h"

#include "dir.h"
#include "sprite.h"
#include "collision.h"

extern char *object_list[];

Object *ObjectCreate(bool solid, int x, int y, int width, int height, int scale, int id, int angle, int vel, double accel);
void ObjectAdd(Object object);
void ObjectUpdate();
void ObjectMove(Object *object);
void ObjectMoveApply(Object *object);
void ObjectReset(Object *object);
void ObjectLockAngle(Object *object, int n);

Object objects[OBJECT_LIMIT];
int object_number;
int object_amount;
