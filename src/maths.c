#include "math.h"

int nround(int x, int n)
{
        return round((double) x / n) * n;
}

int mean(int x, int y)
{
        return (x + y) / 2;
}
