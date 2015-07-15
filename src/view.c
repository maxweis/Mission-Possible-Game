#include "view.h"

void UpdateView()
{
        view->rect->x += view->offset.x;
        view->rect->y += view->offset.y;
        view->offset.x = 0;
        view->offset.y = 0;
}
