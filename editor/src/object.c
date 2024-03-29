#include "object.h"

bool ObjectCollision(SDL_Rect *rect)
{
        for (int i = 0; i < collision_object_number; i++)
                if (Collision(collision_objects[i].sprite->rect, rect) != NONE)
                        return true;
        return false;
}

int CountList(char **list)
{
        int i;
        for (i = 0; list[i] != NULL; i++)
                ;
        return i;
}

void InitObject()
{
        collision_object_number = 0;
        render_object_number = 0;
        object_amount = CountList(object_list);
        object_selection = 0;
}

void AddObject(Object object)
{
        if (object.solid)
                collision_objects[collision_object_number++] = object;
        render_objects[render_object_number++] = object;

}

void DeleteObject(Object object)
{
        if (render_object_number != 0){
                if (object.solid)
                        collision_object_number--;
                render_object_number--;
        }
}

Object *CreateObject(bool solid, int x, int y, int width, int height, int scale, int id, int angle)
{
        Object *temp = malloc(sizeof(Object));
        temp->sprite = SpriteInit(width, height, scale, object_list[id]);

        temp->sprite->angle = angle;
        temp->sprite->frame = 0;

        temp->id = id;

        temp->sprite->rect->x = x;
        temp->sprite->rect->y = y;

        temp->vel.x = 0;
        temp->vel.y = 0;

        temp->solid = solid;
        return temp;
}
