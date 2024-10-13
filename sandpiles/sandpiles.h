#ifndef _SAND_PILES
#define _SAND_PILES

#include <stdlib.h>
#include <stdio.h>


void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid1[3][3]);
void print_grid1(int grid[3][3]);
void fix_sandpile(int grid1[3][3]);

#endif
