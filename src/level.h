#pragma once
#include "defs.h"

#define VALUES_NUMBER 6

#include "object.h"

void LevelLoad(char *level_name);

int level_background;
int object_values[OBJECT_LIMIT][VALUES_NUMBER];
Map *map;
