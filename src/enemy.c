#include "enemy.h"

Enemy enemy_queue[ENEMY_LIMIT];

void EnemyUpdate()
{
        static bool add_enemies = true;

        if (add_enemies){
                add_enemies = false;
                enemy_queue[0].object = ObjectCreate(true, 200, 200, 20, 20, 1, 1, 0, 10, .75);
        }
}
