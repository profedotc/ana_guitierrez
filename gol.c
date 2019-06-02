#include <stdio.h>
#include <stdbool.h>
#include "gol.h"

void gol_init(bool mundo[][TAM_Y])
{
	for ( int i = 0; i < TAM_Y; i++) {
		for ( int j = 0; i < TAM_Y; i++) {
			mundo[i][j] = false;
		}
	}

	mundo[0][1] = true;
	mundo[0][2] = false;
	mundo[1][2] = true;
	mundo[2][0] = true;
	mundo[2][1] = true;
	mundo[2][2] = true;

}

void gol_print(bool mundo[][TAM_Y])
{
	for ( int i = 0; i < TAM_X; i++ ) {
		for ( int j = 0; j < TAM_Y; j++ ) {
			printf("%c ", mundo[i][j] ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(bool mundo1[][TAM_Y], bool mundo2[][TAM_Y])
{
	int count = 0;

	for (int i = 0; i < TAM_X; i++ ) {
        for (int j = 0; j < TAM_Y; j++ ) {
			count = gol_count_neighbors(mundo1, i, j);

			if (mundo1[i][j]) {
				mundo2[i][j] = (count == 3) || (count == 2);
			} else {
				mundo2[i][j] = count == 3;
			}

		}
	}
}

int gol_count_neighbors(bool mundo[][TAM_Y], int x, int y)
{
	int count = 0;
	const int coords[8][2] = {
		{-1, -1}, {0, -1}, {1, -1},
		{-1,  0},          {1,  0},
		{-1,  1}, {0,  1}, {1,  1}
	};

	for ( int i = 0; i < 8; i++ ) {
		count += gol_get_cell(mundo, x + coords[i][0], y + coords[i][1]);
	}

	return count;

}

bool gol_get_cell(bool mundo[][TAM_Y], int x, int y)
{

	if((0 <= x) && (0 <= y) && (x < TAM_X) && (y < TAM_Y)) {
		return mundo[x][y];
	} else {
		return 0;
	}
}