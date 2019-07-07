#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

#define GET_CELL(g, x, y) ( g->worlds[w][x * g->size_y + y] )

struct gol
{
  bool *mem;
  bool *worlds[2];
  int size_x;
  int size_y;
};

enum world { CURRENT, OTHER };

static int count_neighbors(struct gol *g, int x, int y);
static bool get_cell(struct gol *g, enum world w, int x, int y);
static void set_cell(struct gol *g, enum world w, int x, int y, bool b);

struct gol *gol_alloc(int size_x, int size_y) {

	struct gol *g = (struct gol *)malloc(sizeof(struct gol));

	if (!g) {
		printf("No se pudo reservar memoria para mundo\n");
		return NULL;
    }

	g->mem = (bool *)malloc(2 * size_x * size_y * sizeof(bool));

	if (!g->mem) {
		printf("No se pudo reservar memoria para mundo\n");
		return NULL;
    }

	g->size_x = size_x;
	g->size_y = size_y;
	g->worlds[CURRENT] = g->mem;
	g->worlds[OTHER] = g->mem + size_x * size_y;

	return g;
}

void gol_free(struct gol *g)
{
	free(g);
	free(g->mem);
}

void gol_init(struct gol *g, enum gol_init_pattern pattern)
{
	
	for ( int i = 0; i < g->size_x; i++) {
		for ( int j = 0; j < g->size_y; j++) {
			  set_cell(g, CURRENT, i, j, 0);
		}
	}

	switch (pattern) {
    case GOL_GLIDER:
		set_cell(g, CURRENT, 0, 1, true);
		set_cell(g, CURRENT, 0, 2, false);
		set_cell(g, CURRENT, 1, 2, true);
		set_cell(g, CURRENT, 2, 0, true);
		set_cell(g, CURRENT, 2, 1, true);
		set_cell(g, CURRENT, 2, 2, true);
        break;
    case GOL_RANDOM:
        for (int i = 0; i < g->size_x; i++)
            for (int j = 0; j < g->size_y; j++)
                set_cell(g, CURRENT, i, j, rand()%2);
        break;
    }

}

void gol_print(struct gol *g)
{
	for ( int i = 0; i < g->size_x; i++ ) {
		for ( int j = 0; j < g->size_y; j++ ) {
			printf("%c ", get_cell(g, CURRENT, i, j) ? '#' : '.');
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

			if (get_cell(g, CURRENT, i, j)) {
				b = (count == 3) || (count == 2);
				set_cell(g, OTHER, i, j, b);
			} else {
				b = count == 3;
				set_cell(g, OTHER, i, j, b);
			}

		}
	}

	bool *swap;
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
		count += get_cell(g, CURRENT, x + coords[i][0], y + coords[i][1]);
	}

	return count;

}

bool get_cell(struct gol *g, enum world w, int x, int y)
{

	if((0 <= x) && (0 <= y) && (x < g->size_x) && (y < g->size_y)) {
		return GET_CELL(g, x, y);
	} else {
		return 0;
	}
}
void set_cell(struct gol *g, enum world w, int x, int y, bool b)
{
	GET_CELL(g, x, y) = b;
}