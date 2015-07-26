#include "view.h"

void ViewUpdate()
{
        view->rect->x += view->offset.x;
        view->rect->y += view->offset.y;

        view->offset.x = 0;
        view->offset.y = 0;
}
