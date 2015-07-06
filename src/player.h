#include "defs.h"

#include <string.h>
#include <math.h>

extern Player *player;
extern long buffer;
extern Object objects[];
extern int object_number;
extern View *view;
extern Vector mouse_pos;

Player *CreatePlayer();
void PlayerAnimate();
void PlayerMouseRotate();
void PlayerUpdate();
void PlayerMove(Direction dir);
void InitView();

Sprite *SpriteInit(int width, int height, int scale, const char *image_path);
Direction ViewCollision(SDL_Rect *a, int view_length);
Direction ScreenCollision(SDL_Rect *a, int border);
bool MouseMove();
bool ObjectCollision(SDL_Rect *rect);
