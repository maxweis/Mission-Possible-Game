#include "sprite.h"

void SpriteDestroy(void *self)
{
        Sprite *this = self;
        free(this);
        free(this->rect);
}

Sprite *SpriteInit(int width, int height, int scale, const char *ImagePath)
{
        Sprite *temp = malloc(sizeof(Sprite));
        temp->image = IMG_LoadTexture(render, ImagePath);

        temp->scale = scale;
        if (temp->image == NULL)
                fprintf(stderr, "Can not load image at %s\n", ImagePath);

        temp->rect = calloc(1, sizeof(SDL_Rect));

        temp->rect->w = width * temp->scale;
        temp->rect->h = height * temp->scale;

        temp->destroy = &SpriteDestroy;

        return temp;
}

void FrameAdvance(Sprite *sprite){
        sprite->frame++;
}
