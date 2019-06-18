#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

static int count_neighbors(struct gol *g, int x, int y);
static bool get_cell(struct gol *g, int x, int y);

enum world { CURRENT, OTHER };


bool gol_alloc(struct gol *g, int x, int y) {
	
	g->worlds[CURRENT] = (bool **)malloc(x * sizeof(bool *));
	g->worlds[OTHER] = (bool **)malloc(x * sizeof(bool *));
	if (!g->worlds[CURRENT] || !g->worlds[OTHER]) {
		return 0;
	}

	for (int i = 0; i < g->size_x; i++) {
		g->worlds[CURRENT][i] = (bool *)malloc(y * sizeof(bool));
		g->worlds[OTHER][i] = (bool *)malloc(y * sizeof(bool));
		if (!g->worlds[CURRENT][i] || !g->worlds[OTHER][i]) {
			return 0;
		}
	}

	g->size_x = x;
	g->size_y = y;

	return 1;
}

void gol_free(struct gol *g)
{
	for (int i = 0; i < g->size_x; i++) {
		free(g->worlds[CURRENT][i]);
	}
	free(g->worlds[CURRENT]);
}

void gol_init(struct gol *g)
{
	for ( int i = 0; i < g->size_x; i++) {
		for ( int j = 0; j < g->size_y; j++) {
      		g->worlds[CURRENT][i][j] = false;
		}
	}

	g->worlds[CURRENT][0][1] = true;
	g->worlds[CURRENT][0][2] = false;
	g->worlds[CURRENT][1][2] = true;
	g->worlds[CURRENT][2][0] = true;
	g->worlds[CURRENT][2][1] = true;
	g->worlds[CURRENT][2][2] = true;

}

void gol_print(struct gol *g)
{
	for ( int i = 0; i < g->size_x; i++ ) {
		for ( int j = 0; j < g->size_y; j++ ) {
			printf("%c ", g->worlds[CURRENT][i][j] ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(struct gol *g)
{
	int count = 0;

	for (int i = 0; i < g->size_x; i++ ) {
        for (int j = 0; j < g->size_y; j++ ) {
			count = count_neighbors(g, i, j);

			if (g->worlds[CURRENT][i][j]) {
				g->worlds[OTHER][i][j] = (count == 3) || (count == 2);
			} else {
				g->worlds[OTHER][i][j] = count == 3;
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
		return g->worlds[CURRENT][x][y];
	} else {
		return 0;
	}
}