#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

static int count_neighbors(struct gol *g, int x, int y);
static bool get_cell(struct gol *g, int x, int y);
static void set_cell(struct gol *g, int x, int y, bool b);

enum world { CURRENT, OTHER };


bool gol_alloc(struct gol *g, int x, int y) {
	
	g->worlds[CURRENT] = (bool **)malloc(x * y * sizeof(bool *));
	g->worlds[OTHER] = (bool **)malloc(x * y * sizeof(bool *));
	if (!g->worlds[CURRENT] || !g->worlds[OTHER]) {
		return 0;
	}

	g->size_x = x;
	g->size_y = y;

	return 1;
}

void gol_free(struct gol *g)
{
	free(g->worlds[CURRENT]);
	free(g->worlds[OTHER]);
}

void gol_init(struct gol *g)
{
	for ( int i = 0; i < g->size_x; i++) {
		for ( int j = 0; j < g->size_y; j++) {
      		*(g->worlds[CURRENT] + i * g->size_y + j)  = false;
		}
	}

	set_cell(g, 0, 1, true);
	set_cell(g, 0, 2, false);
	set_cell(g, 1, 2, true);
	set_cell(g, 2, 0, true);
	set_cell(g, 2, 1, true);
	set_cell(g, 2, 2, true);

}

void gol_print(struct gol *g)
{
	for ( int i = 0; i < g->size_x; i++ ) {
		for ( int j = 0; j < g->size_y; j++ ) {
			printf("%c ", get_cell(g, i, j) ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(struct gol *g)
{
	int count = 0;
	bool b;

	for (int i = 0; i < g->size_x; i++ ) {
        for (int j = 0; j < g->size_y; j++ ) {
			count = count_neighbors(g, i, j);

			if (get_cell(g, i, j)) {
				b = (count == 3) || (count == 2);
				set_cell(g, i, j, b);
			} else {
				b = count == 3;
				set_cell(g, i, j, b);
			}

		}
	}

	bool **swap;
	swap = g->worlds[CURRENT];
	g->worlds[CURRENT] = g->worlds[OTHER];
	g->worlds[OTHER] = swap;

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

	if((0 <= x) && (0 <= y) && (x < g->size_x) && (y < g->size_y)) {
		return *( g->worlds[CURRENT] + x * g->size_y + y );
	} else {
		return 0;
	}
}
void set_cell(struct gol *g, int x, int y, bool b)
{
	bool *pb = (bool *) b;
	*( g->worlds[CURRENT] + x * g->size_y + y ) = pb;
}