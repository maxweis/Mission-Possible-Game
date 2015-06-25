#include "defs.h"

#include "sprite.h"
#include "collision.h"

extern char *object_list[];

Object collision_objects[OBJECT_LIMIT];
Object render_objects[OBJECT_LIMIT];
int render_object_number;
int collision_object_number;
int object_amount;
int object_selection;

Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, int angle, int id);
void DeleteObject(Object object);

void AddObject(Object object);
bool ObjectCollision(SDL_Rect *rect);
void InitObject();
