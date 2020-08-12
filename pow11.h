#ifndef POW11_H
#define POW11_H

// Probability of getting 4 added as new element to the grid
#define FOUR_PROBABILITY 10

#include "grid.h"

/*
 * Enum: move_t
 * 
 * UP, RIGHT, DOWN, LEFT - move direction
 * 
 * Specifies the move direction of the grid
 */
typedef enum
{
    UP,
    RIGHT,
    DOWN,
    LEFT
} move_t;

/*
 * Structure: Pair
 * 
 * byte_t i - vertical element index
 * 
 * byte_t j - horizontal element index
 * 
 * Helps with storing element indices, so that they are both in one place
 */
typedef struct pair
{
    byte_t i;
    byte_t j;
}pair;

/*
 * Function: move_grid
 * 
 * move_t direction - move direction
 * 
 * struct grid* gr - grid whose elements are being moved
 * 
 * Move every element of the grid gr to the direction as far as possible, summing same value elements. And adds a new element to a random empty position.
 * Meaning if the grid's row looks like this [2][2][4][0], then if we move to the right it becomes [0][0][4][4]. Same for the other sides.
 */
void move_grid(move_t direction, struct grid* gr);

static void move_up(struct grid* gr);

static void move_right(struct grid* gr);

static void move_down(struct grid* gr);

static void move_left(struct grid* gr);

static void add_new_element(struct grid* gr);

static bool move_tiles(struct grid* gr, byte_t curr_i, byte_t curr_j, byte_t next_i, byte_t next_j);

#endif
