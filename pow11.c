#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "pow11.h"
#include "grid.h"

void move_grid(move_t direction, struct grid* gr)
{
    switch (direction)
    {
    case UP:
        move_up(gr);
        break;
    case RIGHT:
        move_right(gr);
        break;
    case DOWN:
        move_down(gr);
        break;
    case LEFT:
        move_left(gr);
        break;
    default:
        break;
    }
    add_new_element(gr);
}

static void move_up(struct grid* gr)
{
    // Ignore the last one, because there are no rows bellow it to move up
    for (byte_t i = 0, size = get_size(gr); i < (size - 1); i++)
    {
        for (byte_t j = 0; j < size; j++)
        {
            // Find the closest non-zero tile bellow and move it
            for (byte_t k = i + 1; k < size; k++)
            {
                if (!move_tiles(gr, i, j, k, j))
                {
                    // There are no more tiles left to add to current tile
                    break;
                }
            }
        }
    }
}

static void move_right(struct grid* gr)
{
    for (byte_t i = 0, size = get_size(gr); i < size; i++)
    {
        // Start from end to ensure move direction priority
        // Ignore the first [0] element because there are no elements left to move to the left of it(definetely a feature!)
        for (byte_t j = (size - 1); j > 0; j--)
        {

            // Find the closest non-zero tile and move it
            // int because we need the negative check when k goes below zero
            for (int k = j - 1; k >= 0; k--)
            {
                if (!move_tiles(gr, i, j, i, k))
                {
                    // There are no more tiles left to add to current tile
                    break;
                }
            }
        }
    }
}

static void move_down(struct grid* gr)
{
    byte_t size = get_size(gr);
    
    // Start from end to ensure move direction priority
    // Ignore the first [0] row because there are no rows above it left to move
    for (byte_t i = size - 1; i > 0; i--)
    {
        for (byte_t j = 0; j < size; j++)
        {   
            // Find the closest non-zero tile and move it
            // int because we need the negative check when k goes below zero
            for (int k = i - 1; k >= 0; k--)
            {
                if (!move_tiles(gr, i, j, k, j))
                {
                    // There are no more tiles left to add to current tile
                    break;
                }
            }
        }
    }
    
}

static void move_left(struct grid* gr)
{
    for (byte_t i = 0, size = get_size(gr); i < size; i++)
    {
        // Ignore the last element [size - 1] because there are no elements left ot move to the right of it
        for (byte_t j = 0; j < (size - 1); j++)
        {
            for (byte_t k = (j + 1); k < size; k++)
            {
                if (!move_tiles(gr, i, j, i, k))
                {
                    // There are no more tiles left to add to current tile
                    break;
                }
            }
        }
    }
}

static void add_new_element(struct grid* gr)
{
    byte_t size = get_size(gr);

    // Stores the number of coordinate pairs which contain zeroes
    byte_t pairs_size = 0;
    struct pair pairs[size * size];

    for (byte_t i = 0; i < size; i++)
    {
        for (byte_t j = 0; j < size; j++)
        {
            if (get_tile(gr, i, j) == 0)
            {
                pairs[pairs_size].i = i;
                pairs[pairs_size].j = j;
                pairs_size++;
            }
        }
    }
    srand(time(0));

    // Get a random index for 0 to pairs_size (exclusive)
    byte_t random_index = rand() % pairs_size;

    // Generate number 4 only FOUR_PROBABILITY (10% by default) percent of times
    uint32_t random_tile = (rand() % 100 + 1) < (100 - FOUR_PROBABILITY) ? 2 : 4;

    struct pair random_position = pairs[random_index];
    set_tile(gr, random_position.i, random_position.j, random_tile);
}

static bool move_tiles(struct grid* gr, byte_t curr_i, byte_t curr_j, byte_t next_i, byte_t next_j)
{
    uint32_t current_tile = get_tile(gr, curr_i, curr_j);
    uint32_t next_tile = get_tile(gr, next_i, next_j);
    if (current_tile == next_tile || current_tile == 0)
    {
        set_tile(gr, curr_i, curr_j, current_tile + next_tile);
        set_tile(gr, next_i, next_j, 0);
        return true;
    }
    return false;
}
