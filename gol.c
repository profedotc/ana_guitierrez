#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

static int count_neighbors(struct gol *g, int x, int y);
static bool get_cell(struct gol *g, int x, int y);
static void set_cell(struct gol *g, int x, int y, bool b);

enum world {
	current = 0, 
	other = 1
	};


bool gol_alloc(struct gol *g, int size_x, int size_y) {
	
	g->mem = (bool *)malloc(2 * size_x * size_y * sizeof(bool));
	if (!g->mem) {
		return 0;
	}

	g->worlds[current] = g->mem;
	g->worlds[other] = g->mem + size_x * size_y * sizeof(bool);
	return 1;
}

void gol_free(struct gol *g)
{
	free(g->worlds[current]);
}

void gol_init(struct gol *g)
{
	for ( int i = 0; i < TAM_X; i++)
		for ( int j = 0; j < TAM_Y; j++)
			*( g->worlds[current] + i * TAM_Y + j ) = false;


	set_cell(g, 0, 1, true);
	set_cell(g, 0, 2, false);
	set_cell(g, 1, 2, true);
	set_cell(g, 2, 0, true);
	set_cell(g, 2, 1, true);
	set_cell(g, 2, 2, true);

}

void gol_print(struct gol *g)
{
	for ( int i = 0; i < TAM_X; i++ ) {
		for ( int j = 0; j < TAM_Y; j++ ) {
			printf("%c ", get_cell(g, i, j) ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(struct gol *g)
{
	int count = 0;

	for (int i = 0; i < TAM_X; i++ ) {
        for (int j = 0; j < TAM_Y; j++ ) {
			count = count_neighbors(g, i, j);

			if (get_cell(g, i, j)) {
				bool b = (count == 3) || (count == 2);
				set_cell(g, i, j, b);
			} else {
				bool b = count == 3;
				set_cell(g, i, j, b);
			}

		}
	}

	g->worlds[other] = g->worlds[current];

}

int count_neighbors(struct gol *g, int x, int y)
{
	int count = 0;
	const int coords[8][2] = {
		{-1, -1}, {0, -1}, {1, -1},
		{-1,  0},          {1,  0},
		{-1,  1}, {0,  1}, {1,  1}
	};

	for ( int i = 0; i < 8; i++ ) {
		count += get_cell(g, x + coords[i][0], y + coords[i][1]);
	}

	return count;

}

bool get_cell(struct gol *g, int x, int y)
{

	if((0 <= x) && (0 <= y) && (x < TAM_X) && (y < TAM_Y)) {
		return GET_CELL(g, x, y);
	} else {
		return 0;
	}
}

void set_cell(struct gol *g, int x, int y, bool b)
{
	GET_CELL(g, x, y) = b;
}