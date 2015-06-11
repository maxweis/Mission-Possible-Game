#include "timer.h"

static Uint32 next_time;

Uint32 TimeLeft()
{
        Uint32 now = SDL_GetTicks();
        if (next_time <= now)
                return 0;
        else
                return next_time - now;
}

void LimitFrames()
{
        buffer++;
        SDL_Delay(TimeLeft());
        next_time += 16;
}
