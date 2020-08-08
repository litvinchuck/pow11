#ifndef GRID_H
#define GRID_H

typedef unsigned char byte_t;

typedef unsigned int uint32_t;

/*
 * Structure: row
 * --------------
 * 
 * byte_t size - length of the row, row size 4 has 4 elements indexes starting from 0 and up to 3
 * 
 * uint32_t tiles[] - array storing the elements of the row
 * 
 * Helper structure for the grid. An array of rows is a grid. Visualise it like rows stacked on top of each other,
 * the first row being on top 
 */
typedef struct row
{
    byte_t size;
    uint32_t tiles[];
}row;

/*
 * Structure: grid
 * ---------------
 * 
 * byte_t size - length of the rows AND height of the collumns of the grid. So a grid size 4 makes a 4x4 grid
 * 
 * row* rows[] - array of row structures, rows contain positive integer values
 * 
 * 
 * The playing area for the game. It stores positive integer values in a grid-like manner.
 * Element indexing starts from top to bottom and from left to right.
 * So the element [0][0] is located in the top left corner of a grid
 * and element [size - 1][size - 1] is bottom right.
 */
typedef struct grid
{
    byte_t size;
    row* rows[];
}grid;

/*
 * Function: create_grid
 * ----------------------------------
 * 
 * byte_t size - length of the rows AND height of the columns of the grid. So a grid size 4 makes a 4x4 grid
 * 
 * Allocates the memory for the grid structure and all the needed row structures.
 * Initialises grid elements with 0 values.
 * Use destroy_grid function to clear allocated memory.
 * 
 * Returns pointer to the created grid.
 */
struct grid* create_grid(byte_t size);

/*
 * Function: set_tile
 * ---------------------------------
 * 
 * struct grid* gr - pointer to the grid on which the tile is set
 * 
 * byte_t i - row number of the tile
 * 
 * byte_t j - column number of the tile
 * 
 * uint32_t val - value the tile being set to
 * 
 * Changes the (i, j) tile value in the grid gr to val.
 * Element indexing starts from top to bottom and from left to right.
 * So the element [0][0] is located in the top left corner of a grid
 * and element [size - 1][size - 1] is bottom right.
 */
void set_tile(struct grid* gr, byte_t i, byte_t j, uint32_t val);

/*
 * Function: get_tile
 * ---------------------------------
 * 
 * struct grid* gr - pointer to the grid on which the tile is set
 * 
 * byte_t i - row number of the tile
 * 
 * byte_t j - column number of the tile
 * 
 * Returns the (i, j) tile value in the grid gr.
 * Element indexing starts from top to bottom and from left to right.
 * So the element [0][0] is located in the top left corner of a grid
 * and element [size - 1][size - 1] is bottom right.
 */
uint32_t get_tile(struct grid* gr, byte_t i, byte_t j);

/*
 * Function: get_size
 * 
 * struct grid* gr - pointer to the grid which size you're getting
 * 
 * Returns the size of the grid.
 * Which is length of the rows AND height of the collumns of the grid. So a grid size 4 makes a 4x4 grid
 */
byte_t get_size(struct grid* gr);

/*
 * Function: destroy_grid
 * 
 * struct grid* gr - pointer to the grid you're destroying
 * 
 * Frees all the memory allocated for grid rows and frees the memory allocated for the grid itself.
 */
void destroy_grid(struct grid* gr);

#endif
