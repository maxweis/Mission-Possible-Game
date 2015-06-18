#include "object.h"

void UpdateObject()
{
}

bool ObjectCollision(SDL_Rect *rect)
{
        for (int i = 0; i < collision_object_number; i++)
                if (Collision(collision_objects[i].sprite->rect, rect) != NONE)
                        return true;
        return false;
}

void InitObject()
{
        collision_object_number = 0;
        render_object_number = 0;
}

void AddObject(Object object)
{
        if (object.solid){
                collision_objects[collision_object_number++] = object;
        }
        render_objects[render_object_number++] = object;

}

Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, char *sprite)
{
        Object *temp = malloc(sizeof(Object));
        temp->sprite = SpriteInit(width, height, scale, sprite);

        temp->sprite->angle = 0;

        temp->sprite->frame = 0;

        temp->sprite->rect->x = x;
        temp->sprite->rect->y = y;

        temp->vel.x = 0;
        temp->vel.y = 0;

        temp->solid = solid;
        return temp;
}
