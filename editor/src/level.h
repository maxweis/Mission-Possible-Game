#include "defs.h"

#include "object.h"

extern int object_selection;

int object_values[OBJECT_LIMIT][5];

void LoadLevel(char *level_name);

void SaveLevel();
