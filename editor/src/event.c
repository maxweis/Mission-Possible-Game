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

void InitEvent()
{
        mouse_hold = false;
        key_hold = false;
        input_scale = 1;
        input_solid = true;
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

        key_press = false;
        if (event.type == SDL_KEYDOWN){
                if (!key_hold)
                        key_press = true;
                key_hold = true;
        }

        if (event.type == SDL_KEYUP)
                key_hold = false;

        if (keystate[SDL_SCANCODE_UP])
                object_selection++;

        if (keystate[SDL_SCANCODE_DOWN])
                object_selection--;

        object_selection %= object_amount;

        mouse_click = false;

        if (event.button.type == SDL_MOUSEBUTTONDOWN){
                if (event.button.button == SDL_BUTTON_LEFT){
                        if (!mouse_hold)
                                mouse_click = true;
                        mouse_hold = true;
                }
        }

        if (event.button.type == SDL_MOUSEBUTTONUP)
                mouse_hold = false;

        if (mouse_click)
                AddObject(*cursor_object);

        if (keystate[SDL_SCANCODE_W] &&
                        key_press)
                input_scale++;

        if (keystate[SDL_SCANCODE_S] &&
                        key_press)
                input_scale--;

        if (keystate[SDL_SCANCODE_SPACE] &&
                        key_press)
                input_solid = !input_solid;

        SDL_GetMouseState(&mouse_x, &mouse_y);
}
