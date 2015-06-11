#include "object.h"

void UpdateObject()
{
}

bool ObjectCollision(SDL_Rect *rect)
{
        for (int i = 0; i < object_number; i++)
                if (Collision(objects[i].sprite->rect, rect) != NONE)
                        return true;
        return false;
}

void InitObject()
{
        object_number = 0;
}

void AddObject(Object object)
{
        if (object.solid){
                objects[object_number] = object;
                object_number++;
        }
}

Object *CreateObject(bool solid)
{
        Object *temp = malloc(sizeof(Object));
        temp->sprite = SpriteInit(64, 64, 2, "art/sprites/object/glass.png");

        temp->sprite->angle = 0;

        temp->sprite->frame = 0;

        temp->sprite->rect->x = 0;
        temp->sprite->rect->y = 0;

        temp->vel.x = 0;
        temp->vel.y = 0;

        temp->solid = solid;
        return temp;
}
