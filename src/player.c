#include "player.h"

void PlayerMove(Direction dir);

Player *CreatePlayer()
{
        Player *temp = malloc(sizeof(Player));

        temp->sprite = SpriteInit(19, 14, 2, "art/sprites/main/base.png");

        temp->sprite->angle = 0;

        temp->sprite->frame = 0;

        temp->run = false;

        temp->move = &PlayerMove;

        temp->sprite->rect->x = 50;
        temp->sprite->rect->y = 50;

        temp->sprite->w = temp->sprite->rect->w;
        temp->sprite->h = temp->sprite->rect->h;

        temp->temp = calloc(1, sizeof(SDL_Rect));
        *temp->temp = *temp->sprite->rect;

        return temp;
}

void MoveApply()
{
        if (!ScreenCollision(player->temp)){
                if (!ObjectCollision(player->temp)){
                        player->sprite->rect->x = player->temp->x;
                        player->sprite->rect->y = player->temp->y;
                }
        }
                player->temp->x = player->sprite->rect->x;
                player->temp->y = player->sprite->rect->y;
}

void PlayerMove(Direction dir)
{
        double accel = 3;

        if (player->run)
                accel = 5;

        if (dir == UP){
                player->temp->y -= accel;
        }

        if (dir == RIGHT){
                player->temp->x += accel;
        }

        if (dir == LEFT){
                player->temp->x -= accel;
        }

        if (dir == DOWN){
                player->temp->y += accel;
        }
                PlayerAnimate();
}

void PlayerMouseRotate()
{
        if (MouseMove()){
                int x_delta = player->sprite->rect->x + player->sprite->rect->w / 2 - mouse_pos.x;
                int y_delta = player->sprite->rect->y + player->sprite->rect->h / 2 - mouse_pos.y;
                int angle = (int) ((atan2(y_delta, x_delta) * 180) / 3.1416);
                if (angle < 0)
                        angle += 360;
                angle += 270;
                angle %= 360;
                player->sprite->angle = angle;
        }
}

void PlayerAnimate()
{
        if (buffer % 15 == 0){
                if (player->sprite->frame < 2){
                        player->sprite->frame++;
                }
                else{
                        player->sprite->frame = 0;
                }
        }
}

void PlayerUpdate()
{
        MoveApply();
        PlayerMouseRotate();
}
