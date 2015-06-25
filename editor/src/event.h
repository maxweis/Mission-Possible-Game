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
void GetEvents();

Vector mouse_pos;
Vector mouse_temp_pos;
int input_scale;
int input_angle;
bool input_solid;
bool mouse_click;
bool mouse_hold;
bool key_press;
bool key_hold;
