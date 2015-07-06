#include "defs.h"

extern char *object_list[];

bool ObjectCollision(SDL_Rect *rect);
Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, int id, int angle);
void AddObject(Object object);

Object objects[OBJECT_LIMIT];
int object_number;
int object_amount;

Direction Collision(SDL_Rect *a, SDL_Rect *b);
Sprite *SpriteInit(int width, int height, int scale, const char *image_path);
