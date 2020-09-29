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
typedef enum move_t
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

/*
 * Function: move_tiles
 * 
 * struct grid* gr - grid whose elements are being moved
 * 
 * byte_t curr_i - current tile ith index
 * 
 * byte_t curr_j - current tile jth index
 * 
 * byte_t next_i - next tile ith index
 * 
 * byte_t next_j - next tile jth index
 * 
 * Takes the current tile (indicies (curr_i, curr_j)) and adds the value of the next tile (indicies  (next_i, next_j)) if
 * both tiles have same value or current tile is zero.
 * 
 * Returns true if next tile value was added to the current tile
 * and false if not
 */
static bool move_tiles(struct grid* gr, byte_t curr_i, byte_t curr_j, byte_t next_i, byte_t next_j);

#endif
