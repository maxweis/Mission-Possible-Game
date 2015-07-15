#include "dir.h"

Direction DirUpdate(Direction dir)
{
        static Direction temp = NONE;
        
        if (temp && dir)
                return mean(temp, dir);
        else{
                temp = dir;
                return dir;
        }
}
