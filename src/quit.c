#include "quit.h"

void GameQuit()
{
        MapFree();
        TTF_Quit();
        IMG_Quit();
        PlayerFree();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(render);
        SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
        SDL_Quit();
}

void PlayerFree()
{
        ObjectFree(player->object);
        free(player);
}

void SpriteFree(Sprite *sprite)
{
        free(sprite->rect);
        free(sprite);
}

void ObjectFree(Object *object)
{
        SpriteFree(object->sprite);
        free(object->temp_rect);
        free(object);
}

void MapFree()
{
        free(map->rect);
        free(map);
}

void EventFree(SDL_Event *event)
{
        free(event);
}
