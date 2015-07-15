#include "defs.h"

extern long buffer;

Player *player;
bool done;

void InitSDL(char *caption);
void LoadLevel(char *level_name);
void LimitFrames();
void CheckGameEvents();
void PlayerUpdate();
void RenderGameScreen();
void StartMenu();
void UpdateObjects();
void UpdateView();
