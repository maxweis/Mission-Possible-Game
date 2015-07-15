#include "init.h"

void InitView()
{
        view = malloc(sizeof(View));
        view->rect = calloc(0, sizeof(SDL_Rect));
        view->rect->w = SWIDTH;
        view->rect->h = SHEIGHT;
        view->offset.x = 0;
        view->offset.y = 0;
}

void InitPlayer()
{
        player = CreatePlayer();
}

void InitSDL(char *caption)
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

        InitEvent();
        InitPlayer();
        InitView();
}
