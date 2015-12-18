#include "main.h"

int main(int argc, char *argv[])
{
        SDLInit("Platformer");

        LevelLoad("level/level1");

        StartMenu();

        while (!done){
                FramesLimit();

                GameEventsCheck();

                /*EnemyUpdate();*/

                PlayerUpdate();

                GameScreenRender();
        }

        /*GameQuit();*/

        return 0;
}
