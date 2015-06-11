#include "event.h"

bool MouseMove()
{
        if (temp_mouse_x == mouse_x && temp_mouse_y == mouse_y)
                return false;
        else{
                temp_mouse_x = mouse_x;
                temp_mouse_y = mouse_y;
                return true;
        }
}

void InitMouse()
{
        SDL_GetMouseState(&temp_mouse_x, &temp_mouse_y);
}

void CheckUserEvents()
{
        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){
                done = true;
                SDL_Quit();
        }

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

        SDL_GetMouseState(&mouse_x, &mouse_y);
}
