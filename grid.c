#include "grid.h"
#include <stdlib.h>

struct grid* create_grid(byte_t size)
{
    struct grid* gr = (struct grid*) malloc(sizeof(struct grid) + sizeof(row*[size]));

    for (byte_t i = 0; i < size; i++)
    {
        gr->rows[i] = (struct row*) malloc(sizeof(struct row) + sizeof(uint32_t[size]));
    }

    gr->size = size;
    for (byte_t i = 0; i < size; i++)
    {
        gr->rows[i]->size = size;
        for (byte_t j = 0; j < size; j++)
        {
            set_tile(gr, i, j, 0);
        }
    }
    return gr;
}

void set_tile(struct grid* gr, byte_t i, byte_t j, uint32_t val)
{
    gr->rows[i]->tiles[j] = val;
}

uint32_t get_tile(struct grid* gr, byte_t i, byte_t j)
{
    return gr->rows[i]->tiles[j];
}

byte_t get_size(struct grid* gr)
{
    return gr->size;
}

void destroy_grid(struct grid* gr)
{
    for (byte_t i = 0, size = get_size(gr); i < size; i++)
    {
        free(gr->rows[i]);
    }
    free(gr);
}
