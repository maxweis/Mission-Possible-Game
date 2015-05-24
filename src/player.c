#include "player.h"

void PlayerMove(DIRECTION dir);

Player *CreatePlayer()
{
        Player *temp = malloc(sizeof(Player));

        temp->sprite = SpriteInit(19, 14, "art/sprites/main/base.png");

        temp->sprite->angle = 0;

        temp->run = false;

        temp->move = &PlayerMove;

        return temp;
}

void PlayerMove(DIRECTION dir)
{
        double accel = 3;

        if (player->run)
                accel = 5;

        if (dir == UP){
                player->sprite->rect->y -= accel;
        }

        if (dir == RIGHT){
                player->sprite->rect->x += accel;
        }

        if (dir == LEFT){
                player->sprite->rect->x -= accel;
        }

        if (dir == DOWN){
                player->sprite->rect->y += accel;
        }
        PlayerAnimate();
}

/*void PlayerMouseRotate()*/
/*{*/
        /*if (MouseMove()){*/
                /*int x, y;*/
                /*SDL_GetMouseState(&x, &y);*/
                /*printf("%d, %d", x, y);*/
                /*printf("hello");*/
                /*int x_delta = player->sprite->rect->x + player->sprite->rect->w / 2;*/
                /*int y_delta = player->sprite->rect->y + player->sprite->rect->h / 2;*/
                /*player->sprite->angle = (atan2(y_delta, x_delta) * 180.0) / 3.1416;*/
                /*//fix mouse rotation math*/
        /*}*/
/*}*/

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
