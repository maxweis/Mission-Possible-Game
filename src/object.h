#include "defs.h"

#include "collision.h"
#include "sprite.h"

extern Object *object;
extern char *object_list[];

Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, int angle, int id);
bool ObjectCollision(SDL_Rect *rect);
void AddObject(Object object);
void InitObject();

Object collision_objects[OBJECT_LIMIT];
Object render_objects[OBJECT_LIMIT];
int render_object_number;
int collision_object_number;
int object_amount;
