#include "defs.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "event.h"

void GameQuit();
void ViewFree();
void PlayerFree();
void SpriteFree(Sprite *sprite);
void ObjectFree(Object *object);
void EventFree(SDL_Event *event);
void MapFree();
