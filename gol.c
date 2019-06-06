#include <stdio.h>
#include <stdbool.h>
#include "gol.h"

void gol_init(struct gol *g)
{
	for ( int i = 0; i < TAM_Y; i++) {
		for ( int j = 0; i < TAM_Y; i++) {
      		g->worlds[0][i][j] = false;
		}
	}

	g->worlds[0][0][1] = true;
	g->worlds[0][0][2] = false;
	g->worlds[0][1][2] = true;
	g->worlds[0][2][0] = true;
	g->worlds[0][2][1] = true;
	g->worlds[0][2][2] = true;
	g->current_world = 0;

}

void gol_print(struct gol *g)
{
	for ( int i = 0; i < TAM_X; i++ ) {
		for ( int j = 0; j < TAM_Y; j++ ) {
			printf("%c ", g->worlds[g->current_world][i][j] ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(struct gol *g)
{
	int count = 0;
	bool shift_world = !g->current_world;

	for (int i = 0; i < TAM_X; i++ ) {
        for (int j = 0; j < TAM_Y; j++ ) {
			count = gol_count_neighbors(g, i, j);

			if (g->worlds[g->current_world][i][j]) {
				g->worlds[shift_world][i][j] = (count == 3) || (count == 2);
			} else {
				g->worlds[shift_world][i][j] = count == 3;
			}

		}
	}
	g->current_world = !g->current_world;

}

int gol_count_neighbors(struct gol *g, int x, int y)
{
	int count = 0;
	const int coords[8][2] = {
		{-1, -1}, {0, -1}, {1, -1},
		{-1,  0},          {1,  0},
		{-1,  1}, {0,  1}, {1,  1}
	};

	for ( int i = 0; i < 8; i++ ) {
		count += gol_get_cell(g, x + coords[i][0], y + coords[i][1]);
	}

	return count;

}

bool gol_get_cell(struct gol *g, int x, int y)
{

	if((0 <= x) && (0 <= y) && (x < TAM_X) && (y < TAM_Y)) {
		return g->worlds[g->current_world][x][y];
	} else {
		return 0;
	}
}