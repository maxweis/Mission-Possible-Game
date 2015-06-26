#include "event.h"

bool MouseMove()
{
        if (event.motion.x > 0 || event.motion.y > 0)
                return true;
        else
                return false;
}

void InitEvent()
{
        mouse_hold = false;
        key_hold = false;
        input_angle = 0;
        input_scale = 1;
        input_solid = true;
}

void HandleButtonPress(){
        key_press = false;
        if (event.type == SDL_KEYDOWN){
                if (!key_hold)
                        key_press = true;
                key_hold = true;
        }

        if (event.type == SDL_KEYUP)
                key_hold = false;

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
}

void GetEvents()
{
        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
        SDL_PollEvent(&event);
        keystate = SDL_GetKeyboardState(NULL);
        HandleButtonPress();
}

void CheckUserEvents()
{
        GetEvents();
        if (event.type == SDL_QUIT)
                done = true;

        if (keystate[SDL_SCANCODE_D] &&
                        key_press)
                object_selection++;

        if (keystate[SDL_SCANCODE_A] &&
                        key_press){
                if (object_selection > 0)
                        object_selection--;
                else
                        object_selection = object_amount - 1;
        }

        object_selection %= object_amount;

        if (mouse_click)
                AddObject(*cursor_object);

        if (keystate[SDL_SCANCODE_W] &&
                        key_press)
                input_scale++;

        if (keystate[SDL_SCANCODE_S] &&
                        key_press)
                if (input_scale > 1)
                        input_scale--;

        if (keystate[SDL_SCANCODE_SPACE] &&
                        key_press)
                input_solid = !input_solid;

        if (keystate[SDL_SCANCODE_Z] &&
                        key_press)
                DeleteObject(*cursor_object);

        if (keystate[SDL_SCANCODE_LEFT] &&
                        key_press){
                if (input_angle > 0)
                        input_angle -= 90;
                else
                        input_angle += 270;
        }

        if (keystate[SDL_SCANCODE_RIGHT] &&
                        key_press)
                input_angle += 90;

        input_angle %= 360;

        if (keystate[SDL_SCANCODE_X])
                SDL_GetMouseState(&mouse_pos.x, NULL);
        else if (keystate[SDL_SCANCODE_Y])
                SDL_GetMouseState(NULL, &mouse_pos.y);
        else
                SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);

        mouse_pos.x %= SWIDTH;
        mouse_pos.y %= SHEIGHT;
        SDL_WarpMouseInWindow(window, mouse_pos.x, mouse_pos.y);
}
