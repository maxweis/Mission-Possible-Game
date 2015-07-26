#include "player.h"

Player *PlayerCreate()
{
        Player *temp = malloc(sizeof(Player));

        temp->object = ObjectCreate(true, 10, 10, 19, 14, 2, 0, 0, 3, 3);

        temp->run = false;

        temp->health = 1;

        temp->attack = 5;

        temp->defense = 0;

        return temp;
}

void PlayerMouseRotate()
{
        if (MouseMove() && !player->object->collision){
                int x_delta = player->object->sprite->rect->x + player->object->sprite->rect->w / 2 - mouse_pos.x;
                int y_delta = player->object->sprite->rect->y + player->object->sprite->rect->h / 2 - mouse_pos.y;
                int angle = (int) ((atan2(y_delta, x_delta) * 180) / 3.1416);
                if (angle < 0)
                        angle += 360;
                angle += 270;
                angle %= 360;
                player->object->sprite->angle = angle;
        }
}

void PlayerAnimate()
{
        if (!player->object->move)
                player->object->sprite->frame = 0;

        else if (!(buffer % 15) && !player->object->collision){
                if (player->object->sprite->frame < 2){
                        player->object->sprite->frame++;
                }
                else{
                        player->object->sprite->frame = 0;
                }
        }
}

void PlayerUpdate()
{
        if (player->run){
                player->object->vel.x = 5;
                player->object->vel.y = 5;
        }
        else{
                player->object->vel.x = 3;
                player->object->vel.y = 3;
        }
        ObjectMove(player->object);
        ObjectMoveApply(player->object);
        PlayerAnimate();
        PlayerMouseRotate();
        ObjectReset(player->object);
}
