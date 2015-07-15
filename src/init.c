#include "init.h"

void ViewInit()
{
        view = malloc(sizeof(View));
        view->rect = calloc(0, sizeof(SDL_Rect));
        view->rect->w = SWIDTH;
        view->rect->h = SHEIGHT;
}

void PlayerInit()
{
        player = PlayerCreate();
}

void SDLInit(char *caption)
{
        if (SDL_Init(SDL_INIT_EVERYTHING))
                fprintf(stderr, "Unable to initialize SDL2: %s\n", SDL_GetError());

        if (TTF_Init())
                fprintf(stderr, "TTF_Init() failed (install sdl2_ttf) : %s\n", TTF_GetError());

        window = SDL_CreateWindow(caption,
                        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                        SWIDTH, SHEIGHT,
                        SDL_WINDOW_OPENGL);

        render = SDL_CreateRenderer(window, -1,
                        SDL_RENDERER_ACCELERATED);

        SDL_SetRelativeMouseMode(true);
        SDL_RenderSetLogicalSize(render, SWIDTH, SHEIGHT);

        EventInit();
        PlayerInit();
        ViewInit();
}
