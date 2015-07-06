#include "defs.h"

#define VALUES_NUMBER 6

void LoadLevel(char *level_name);

int level_background;
int object_values[OBJECT_LIMIT][VALUES_NUMBER];
Map *map;

void AddObject(Object object);
Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, int id, int angle);
