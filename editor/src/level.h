#include "defs.h"

#include "object.h"
#include "event.h"
#include "render.h"

#define VALUES_NUMBER 6

extern int object_selection;

int object_values[OBJECT_LIMIT][VALUES_NUMBER];

int level_background;

Vector input_player_pos;

void LoadLevel(char *level_name);

void SaveLevel();

void PromptUser();
