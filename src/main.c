#include "main.h"

int main(int argc, char *argv[])
{
        InitSDL("Platformer");

        StartMenu();

        LoadLevel("level/level1");

        while (!done){
                LimitFrames();

                CheckGameEvents();

                PlayerUpdate();

                UpdateObjects();

                UpdateView();

                RenderGameScreen();
        }

        /*QuitSDL();*/

        return 0;
}
