#include "main.h"

//ISSUES
//fix rotated collision

int main(int argc, char *argv[])
{
        InitSDL("Platformer");

        player = CreatePlayer();

        LoadLevel("level1");
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
