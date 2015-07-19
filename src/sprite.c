#include "sprite.h"

Sprite *SpriteInit(int width, int height, int scale, const char *image_path)
{
        Sprite *temp = malloc(sizeof(Sprite));
        temp->image = IMG_LoadTexture(render, image_path);

        temp->scale = scale;
        if (!temp->image)
                fprintf(stderr, "Can not load image at %s\n", image_path);

        temp->rect = calloc(0, sizeof(SDL_Rect));

        temp->frame = 0;
        temp->temp_angle = 0;
        temp->angle = 0;

        if (height == 0 || width == 0){
                SDL_QueryTexture(temp->image, NULL, NULL, &temp->rect->w, &temp->rect->h);
                temp->rect->w *= temp->scale;
                temp->rect->h *= temp->scale;
        }
        else{
        temp->rect->w = width * temp->scale;
        temp->rect->h = height * temp->scale;
        }

        return temp;
}

void FrameAdvance(Sprite *sprite){
        sprite->frame++;
}
