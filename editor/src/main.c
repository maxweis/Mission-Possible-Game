#include "main.h"

int main(int argc, char *argv[])
{
        InitSDL("Level Creator");

        if (argc > 1)
                LoadLevel(argv[1]);

        while (!done){
                LimitFrames();

                CheckUserEvents();

                RenderScreen();
        }
        SaveLevel();

        return 0;
}
