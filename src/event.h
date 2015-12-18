#pragma once
#include "defs.h"

#include "dir.h"
#include "maths.h"
#include "player.h"

extern bool done;
extern Player *player;
extern int menu_selection;
extern bool menu_enter;

bool MouseMove();
void UserEventsCheck();
void GameEventsCheck();
void MenuEventsCheck();
void MouseInit();
void EventInit();

Vector mouse_pos;
bool mouse_click;
bool mouse_hold;
bool key_press;
bool key_hold;
SDL_Event event;
const Uint8 *keystate;
