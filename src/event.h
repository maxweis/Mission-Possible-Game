#include "defs.h"

extern bool done;
SDL_Event event;
const Uint8 *keystate;

extern Player *player;

bool MouseMove();

void CheckUserEvents();
void InitMouse();
void InitEvent();

int mouse_x, mouse_y;
int temp_mouse_x, temp_mouse_y;
bool mouse_click;
bool mouse_hold;
bool key_press;
bool key_hold;
