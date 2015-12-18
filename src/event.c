#include "event.h"

bool MouseMove()
{
        int x, y;
        SDL_GetRelativeMouseState(&x, &y);
        return x || y;
}

void EventInit()
{
        mouse_hold = false;
        key_hold = false;
}

void ButtonPressHandle()
{
        /*SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);*/
        keystate = SDL_GetKeyboardState(NULL);

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

void UniversalEventsCheck()
{
        if (event.type == SDL_QUIT)
                done = true;

        if (keystate[SDL_SCANCODE_ESCAPE])
                done = true;
}

void MenuEventsCheck()
{
        ButtonPressHandle();
        while (SDL_PollEvent(&event)){
                UniversalEventsCheck();
        }

        if ((keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) &&
                        key_press)
                menu_selection--;

        if ((keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN]) &&
                        key_press)
                menu_selection++;

        if (keystate[SDL_SCANCODE_RETURN] || keystate[SDL_SCANCODE_SPACE] ||
                        (mouse_click && event.button.button == SDL_BUTTON_LEFT))
                menu_enter = true;

        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        mouse_pos.x = mouse_x;
        mouse_pos.y = mouse_y;
}

void GameEventsCheck()
{
        ButtonPressHandle();
        while (SDL_PollEvent(&event)){
                UniversalEventsCheck();
        }

        player->run = keystate[SDL_SCANCODE_LSHIFT] && key_hold;

        if (keystate[SDL_SCANCODE_W])
                player->object->move = DirUpdate(NORTH);

        if (keystate[SDL_SCANCODE_D])
                player->object->move = DirUpdate(EAST);

        if (keystate[SDL_SCANCODE_S])
                player->object->move = DirUpdate(SOUTH);

        if (keystate[SDL_SCANCODE_A])
                player->object->move = DirUpdate(WEST);

        if (keystate[SDL_SCANCODE_UP] && key_press)
                PlayerHealthAdd(1);

        /*if (keystate[SDL_SCANCODE_RIGHT])*/
                /*view->offset.x++;*/

        if (keystate[SDL_SCANCODE_DOWN] && key_press)
                PlayerHealthAdd(-1);

        /*if (keystate[SDL_SCANCODE_LEFT])*/
                /*view->offset.x--;*/

        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        mouse_pos.x = mouse_x;
        mouse_pos.y = mouse_y;
}
