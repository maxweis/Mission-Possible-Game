#include "timer.h"

unsigned int frames;

void ResetFrames()
{
        frames = SDL_GetTicks() + 16;
}

void UpdateFrames()
{
        buffer++;
        unsigned int ticks = SDL_GetTicks();

        if (frames < ticks)
                return;
        else if (frames > ticks + 16)
                SDL_Delay(16);
        else
                SDL_Delay(frames - ticks);

        ResetFrames();
}

void InitTimer()
{
        buffer = 0;
        ResetFrames();
}
