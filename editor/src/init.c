#include "init.h"

void InitSDL(char *caption)
{
        if (SDL_Init(SDL_INIT_EVERYTHING))
                fprintf(stderr, "Unable to initialize SDL2: %s\n", SDL_GetError());

        window = SDL_CreateWindow(caption,
                        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                        SWIDTH, SHEIGHT,
                        SDL_WINDOW_OPENGL);

        render = SDL_CreateRenderer(window, -1,
                        SDL_RENDERER_ACCELERATED);

        SDL_ShowCursor(false);
        SDL_RenderSetLogicalSize(render, SWIDTH, SHEIGHT);

        if (IMG_Init(0))
                fprintf(stderr, "Unable to initialize SDL_image: %s\n", SDL_GetError());
        InitObject();
        InitEvent();
}
