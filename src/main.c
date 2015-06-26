#include "main.h"

//ISSUES
//fix rotated collision

int main(int argc, char *argv[])
{
        InitSDL("Platformer");

        player = CreatePlayer();

        LoadLevel("level/level1");

        while (!done){
                LimitFrames();

                CheckUserEvents();

                PlayerUpdate();

                RenderScreen();
        }

        /*QuitSDL();*/

        return 0;
}
