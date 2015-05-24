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

void PlayerMouseRotate()
{
        int x, y;
        SDL_GetMouseState(&x, &y);
        int x_delta = player->sprite->rect->x + player->sprite->rect->w / 2 - x;
        int y_delta = player->sprite->rect->y + player->sprite->rect->h / 2 - y;
        player->sprite->angle = 265 + ((atan2(y_delta, x_delta) * 180.0) / 3.1416);
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

void UpdatePlayer()
{
        PlayerMouseRotate();
}
