#include <stdio.h>
#include <ncurses.h>
#include "grid.h"
#include "term.h"
#include "pow11.h"

int main(int argc, char *argv[])
{
    //initscr();
    //printw("Hello, ncurses!");
    //refresh();
    //getch();
    //endwin();

    struct grid* gr = create_grid(4);
    set_tile(gr, 0, 0, 2);
    set_tile(gr, 0, 1, 2);
    set_tile(gr, 0, 2, 2);
    set_tile(gr, 0, 3, 2);
    move_grid(LEFT, gr);
    draw_grid(gr);
    destroy_grid(gr);
    
    return 0;
}
