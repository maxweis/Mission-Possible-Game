#include "sprite.h"

void SpriteDestroy(void *self)
{
        Sprite *this = self;
        free(this);
}

Sprite *SpriteInit(int width, int height, const char *ImagePath)
{
        Sprite *temp = malloc(sizeof(Sprite));
        temp->image = IMG_LoadTexture(render, ImagePath);

        if (temp->image == NULL)
                fprintf(stderr, "Can not load image at %s", ImagePath);

        temp->rect = calloc(1, sizeof(SDL_Rect));

        temp->rect->w = width;
        temp->rect->h = height;

        temp->destroy = &SpriteDestroy;

        return temp;
}

void FrameAdvance(Sprite *sprite){
        sprite->frame++;
}
