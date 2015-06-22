#include "defs.h"

#include "object.h"

extern int object_selection;
extern int object_amount;
extern bool done;
extern Object *cursor_object;

SDL_Event event;
const Uint8 *keystate;

bool MouseMove();

void CheckUserEvents();
void InitMouse();
void InitEvent();

int mouse_x, mouse_y;
int temp_mouse_x, temp_mouse_y;
int input_scale;
bool input_solid;
bool mouse_click;
bool mouse_hold;
bool key_press;
bool key_hold;
