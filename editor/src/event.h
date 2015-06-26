#include "defs.h"

#include "object.h"

extern int object_selection;
extern int object_amount;
extern bool done;
extern Object *cursor_object;
extern SDL_Window *window;

SDL_Event event;
const Uint8 *keystate;

bool MouseMove();

void CheckUserEvents();
void InitEvent();
void GetEvents();

Vector mouse_pos;
int input_scale;
int input_angle;
bool input_solid;
bool mouse_click;
bool mouse_hold;
bool key_press;
bool key_hold;
