#include "menu.h"

void OptionsMenu()
{
}

void StartMenu()
{
        while (!menu_enter && !done){
                FramesLimit();
                MenuEventsCheck();
                if (menu_selection > 0)
                        menu_selection %= 3;
                else
                        menu_selection = 0;
                StartMenuRender();
        }

        if (!done){
                switch(menu_selection){
                        case 0:
                                break;
                        case 1:
                                menu_selection = 0;
                                menu_enter = false;
                                OptionsMenu();
                                break;
                        case 2:
                                done = true;
                                break;
                }
        }
}
