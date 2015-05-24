#include "main.h"

int main(int argc, char *argv[])
{
        InitTimer();

        InitSDL("Platformer");

        player = CreatePlayer();

        while (!done){
                CheckWindowEvent();

                CheckPlayerEvent(player);

                UpdateObjects();

                RenderScreen();

                UpdateFrames();
        }

        /*QuitSDL();*/

        return 0;
}
