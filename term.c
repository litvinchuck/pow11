#include <stdio.h>
#include "grid.h"

void draw_grid(struct grid* gr)
{
    for (byte_t i = 0, size = get_size(gr); i < size; i++)
    {
        for (byte_t j = 0; j < size; j++)
        {
            printf("%d ", get_tile(gr, i, j));
        }
        printf("\n");
    }
}
