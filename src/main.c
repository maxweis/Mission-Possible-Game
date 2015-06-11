#include "main.h"

//ISSUES
//fix rotated collision

int main(int argc, char *argv[])
{
        InitSDL("Platformer");

        player = CreatePlayer();

        object = CreateObject(true);

        AddObject(*object);

        while (!done){
                LimitFrames();

                CheckUserEvents();

                PlayerUpdate();

                UpdateObject();

                RenderScreen();
        }

        /*QuitSDL();*/

        return 0;
}
