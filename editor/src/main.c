#include "main.h"

//ADD PLAYER START COORDINATES
int main(int argc, char *argv[])
{
        InitSDL("Level Creator");

        if (argc > 1)
                LoadLevel(argv[1]);
        else
                PromptUser();

        while (!done){
                LimitFrames();

                CheckUserEvents();

                RenderScreen();
        }
        SaveLevel();

        return 0;
}
