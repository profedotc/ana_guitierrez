#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

static int count_neighbors(struct gol *g, int x, int y);
static bool get_cell(struct gol *g, int x, int y);

enum world {
	current = 0, 
	other = 1
	};


bool gol_alloc(struct gol *g, int x, int y) {
	
	g->worlds[current] = (bool **)malloc(x * sizeof(bool *));
	g->worlds[other] = (bool **)malloc(x * sizeof(bool *));
	if (!g->worlds[current] || !g->worlds[other]) {
		return 0;
	}

	for (int i = 0; i < y; i++) {
		g->worlds[current][i] = (bool *)malloc(y * sizeof(bool));
		g->worlds[other][i] = (bool *)malloc(y * sizeof(bool));
		if (!g->worlds[current][i] || !g->worlds[other][i]) {
			return 0;
		}
	}

	return 1;
}

void gol_free(struct gol *g, int x)
{
	for (int i = 0; i < x; i++) {
		free(g->worlds[current][i]);
		free(g->worlds[other][i]);
	}
	free(g->worlds[current]);
	free(g->worlds[other]);
}

void gol_init(struct gol *g)
{
	for ( int i = 0; i < TAM_X; i++) {
		for ( int j = 0; j < TAM_Y; j++) {
      		g->worlds[current][i][j] = false;
		}
	}

	g->worlds[current][0][1] = true;
	g->worlds[current][0][2] = false;
	g->worlds[current][1][2] = true;
	g->worlds[current][2][0] = true;
	g->worlds[current][2][1] = true;
	g->worlds[current][2][2] = true;

}

void gol_print(struct gol *g)
{
	for ( int i = 0; i < TAM_X; i++ ) {
		for ( int j = 0; j < TAM_Y; j++ ) {
			printf("%c ", g->worlds[current][i][j] ? '#' : '.');
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

			if (g->worlds[current][i][j]) {
				g->worlds[other][i][j] = (count == 3) || (count == 2);
			} else {
				g->worlds[other][i][j] = count == 3;
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
		return g->worlds[current][x][y];
	} else {
		return 0;
	}
}