#include "player.h"
#include "render.h"

void PlayerInit()
{
        player = PlayerCreate();
}

Player *PlayerCreate()
{
        Player *temp = malloc(sizeof(Player));

        temp->object = ObjectCreate(true, 10, 10, 19, 14, 2, 0, 0, 3, .5);

        temp->run = false;

        temp->health = 10;

        temp->health_max = 10;

        temp->attack = 5;

        temp->defense = 0;

        temp->alive = true;

        return temp;
}

void PlayerMouseRotate()
{
        if (MouseMove()){
                int x_delta = player->object->sprite->rect->x + player->object->sprite->rect->w / 2 - mouse_pos.x;
                int y_delta = player->object->sprite->rect->y + player->object->sprite->rect->h / 2 - mouse_pos.y;
                int angle = (int) ((atan2(y_delta, x_delta) * 180) / 3.1416);
                if (angle < 0)
                        angle += 360;
                angle += 270;
                angle %= 360;
                player->object->sprite->temp_angle = angle;
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

void PlayerHealthAdd(int amount)
{
        player->health += amount;
        if (player->health <= 0){
                player->health = 0;
                player->alive = false;
        }

        if (player->health > player->health_max)
                player->health = player->health_max;
}

void PlayerUpdate()
{
        if (player->run)
                player->object->vel = 5;
        else
                player->object->vel = 3;
        player->object->sprite->temp_angle = player->object->sprite->angle;
        ObjectMove(player->object);
        PlayerMouseRotate();
        if (player->object->collision)
                PlayerHealthAdd(-1);
        ObjectLockAngle(player->object, 30);
        BoundUpdate(player->object);
        ObjectMoveApply(player->object);
        PlayerAnimate();
        ObjectReset(player->object);
}
