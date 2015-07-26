#include "object.h"

int CountList(char **list)
{
        int i;
        for (i = 0; list[i]; i++)
                ;
        return i;
}

void InitObject()
{
        object_number = 0;
        object_amount = CountList(object_list);
}

void ObjectAdd(Object object)
{
        objects[object_number++] = object;
}

Object *ObjectCreate(bool solid, int x, int y, int width, int height, int scale, int id, int angle, int vel_x, int vel_y)
{
        Object *temp = malloc(sizeof(Object));
        temp->sprite = SpriteInit(width, height, scale, object_list[id]);

        temp->sprite->angle = angle;
        temp->sprite->frame = 0;

        temp->id = id;
        temp->sprite->rect->x = x;
        temp->sprite->rect->y = y;

        temp->move = NONE;

        temp->temp_rect = calloc(0, sizeof(SDL_Rect));

        *temp->temp_rect = *temp->sprite->rect;

        temp->dimensions.x = temp->sprite->rect->w;
        temp->dimensions.y = temp->sprite->rect->h;

        temp->vel.x = vel_x;
        temp->vel.y = vel_y;

        temp->solid = solid;
        return temp;
}

void ObjectReset(Object *object)
{
        object->move = DirUpdate(NONE);
}

void ObjectMove(Object *object)
{
        static bool movement = true;

        static double accel = .5;

        static Direction old;

        if (accel < 1.5)
                accel += .06;

        movement = true;
        switch(object->move){
                case NORTH:
                        object->temp_rect->y -= (object->vel.y * accel);
                        break;
                case NORTHEAST:
                        object->temp_rect->x += (object->vel.x * accel * .7);
                        object->temp_rect->y -= (object->vel.y * accel * .7);
                        break;
                case EAST:
                        object->temp_rect->x += (object->vel.x * accel);
                        break;
                case SOUTHEAST:
                        object->temp_rect->x += (object->vel.x * accel * .7);
                        object->temp_rect->y += (object->vel.y * accel * .7);
                        break;
                case SOUTH:
                        object->temp_rect->y += (object->vel.y * accel);
                        break;
                case SOUTHWEST:
                        object->temp_rect->x -= (object->vel.x * accel * .7);
                        object->temp_rect->y += (object->vel.y * accel * .7);
                        break;
                case WEST:
                        object->temp_rect->x -= (object->vel.x * accel);
                        break;
                case NORTHWEST:
                        object->temp_rect->x -= (object->vel.x * accel * .7);
                        object->temp_rect->y -= (object->vel.y * accel * .7);
                        break;
                case NONE:
                        movement = false;
        }
        if (!movement || (object->move == -old && object->move && old))
                accel = .5;

        old = object->move;
}

Direction ObjectCollisions(Object *object)
{
        Direction collision;
        if (!(collision = ScreenCollision(object->temp_rect, 5))){
                if (!(collision = ObjectsCollision(object->temp_rect)))
                        collision = false;
        }
        return collision;
}

void ObjectMoveApply(Object *object)
{
        if (!(object->collision = ObjectCollisions(object))){
                object->sprite->rect->x = object->temp_rect->x;
                object->sprite->rect->y = object->temp_rect->y;
        }
        object->temp_rect->x = object->sprite->rect->x;
        object->temp_rect->y = object->sprite->rect->y;
}

void UpdateObject()
{
}
