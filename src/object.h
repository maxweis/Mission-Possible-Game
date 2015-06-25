#include "defs.h"

#include "sprite.h"
#include "collision.h"

extern Object *object;
extern char *object_list[];

Object collision_objects[OBJECT_LIMIT];
Object render_objects[OBJECT_LIMIT];
int render_object_number;
int collision_object_number;
int object_amount;

Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, int angle, int id);

void AddObject(Object object);
bool ObjectCollision(SDL_Rect *rect);
void InitObject();
