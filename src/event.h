#include "defs.h"

extern bool done;
extern Player *player;

bool MouseMove();
void CheckUserEvents();
void InitMouse();
void InitEvent();

Vector mouse_pos;
bool mouse_click;
bool mouse_hold;
bool key_press;
bool key_hold;
SDL_Event event;
const Uint8 *keystate;
