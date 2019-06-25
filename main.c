#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;
	struct gol g;

	if (!gol_alloc(&g, 10, 15)) {
		printf("No se pudo reservar memoria para mundo\n");
		return EXIT_FAILURE;
    }

	gol_init(&g);

	do {
		printf("\033cIteration %d\n", i++);

		gol_print(&g);

		printf("\n\n");
		gol_step(&g);

	} while (getchar() != 'q');

	gol_free(&g);

	return EXIT_SUCCESS;
}
