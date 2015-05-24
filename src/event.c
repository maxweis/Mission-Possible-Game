#include "event.h"

void CheckWindowEvent()
{
        if (SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT)
                        done = true;
        }
}

bool MouseMove()
{
        return event.type == SDL_MOUSEMOTION;
}

void CheckPlayerEvent()
{
        keystate = SDL_GetKeyboardState(NULL);

        if (keystate[SDL_SCANCODE_LSHIFT])
                player->run = true;
        else
                player->run = false;

        if (keystate[SDL_SCANCODE_W])
                player->move(UP);

        if (keystate[SDL_SCANCODE_D])
                player->move(RIGHT);

        if (keystate[SDL_SCANCODE_S])
                player->move(DOWN);

        if (keystate[SDL_SCANCODE_A])
                player->move(LEFT);

        /*player->update();*/
}
