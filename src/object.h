#include "defs.h"

#include "sprite.h"
#include "collision.h"

#define OBJECT_LIMIT 1000

extern Object *object;
Object objects[OBJECT_LIMIT];
int object_number;

Object *CreateObject(bool solid);

void UpdateObject();
void AddObject(Object object);
bool ObjectCollision(SDL_Rect *rect);
void InitObject();
