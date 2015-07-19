#include "quit.h"

void GameQuit()
{
        ViewFree();
        MapFree();
        TTF_Quit();
        IMG_Quit();
        PlayerFree();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(render);
        SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
        SDL_Quit();
}

void ViewFree()
{
        free(view->rect);
        free(view);
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
