#include "object.h"

bool ObjectCollision(SDL_Rect *rect)
{
        for (int i = 0; i < object_number; i++)
                if (objects[i].solid && 
                                Collision(objects[i].sprite->rect, rect) != NONE)
                        return true;
        return false;
}

void ObjectViewUpdate()
{
        for (int i = 0; i < object_number; i++){
                objects[i].sprite->rect->x -= view->offset.x;
                objects[i].sprite->rect->y -= view->offset.y;
        }
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
        object_number = 0;
        object_amount = CountList(object_list);
}

void AddObject(Object object)
{
        objects[object_number++] = object;
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

void UpdateObjects()
{
        ObjectViewUpdate();
}
