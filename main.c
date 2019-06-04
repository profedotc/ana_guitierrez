#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int index = 0;
	int i = 0;
	bool mundo[2][TAM_X][TAM_Y];

	gol_init(mundo[index]);

	do {
		printf("\033cIteration %d\n", i++);

		gol_print(mundo[index]);

		printf("\n\n");
		int shift_index = index ? 0 : 1;
		gol_step(mundo[index], mundo[shift_index]);
		index = shift_index;

	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
