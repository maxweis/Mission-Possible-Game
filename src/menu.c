#include "menu.h"

void OptionsMenu()
{
}

void LimitSelection(int *selection, int amount)
{
        if (*selection < 0)
                *selection = amount - 1;

        if (*selection > amount - 1)
                *selection = 0;
}

void StartMenu()
{
        while (!menu_enter && !done){
                FramesLimit();
                MenuEventsCheck();
                LimitSelection(&menu_selection, 3);
                StartMenuRender();
        }

        if (!done){
                switch(menu_selection){
                        case 0: //start game
                                break;
                        case 1: //options
                                menu_selection = 0;
                                menu_enter = false;
                                OptionsMenu();
                                break;
                        case 2: //exit
                                done = true;
                                break;
                }
        }
}
