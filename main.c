#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 3
#define TAM_Y 3

void gol_init(bool mundo[][TAM_Y]);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundo1[][TAM_Y], bool mundo2[][TAM_Y]);
int gol_count_neighbors(bool mundo[][TAM_Y], int x, int y);
bool gol_get_cell(bool mundo[][TAM_Y], int x, int y);
void gol_copy(bool mundo1, bool mundo2);

int main()
{
	int i = 0;
	// TODO: Declara dos mundos
	bool mundo1[TAM_X][TAM_Y];
	bool mundo2[TAM_X][TAM_Y];

	// TODO: inicializa el mundo
	gol_init(mundo1);

	do {
		printf("\033cIteration %d\n", i++);
		
		// TODO: Imprime el mundo
		gol_print(mundo1);

		printf("\n\n");
		// TODO: Itera
		gol_step(mundo1, mundo2);

	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void gol_init(bool mundo[][TAM_Y])
{
	// TODO: Poner el mundo a false
	for ( int i = 0; i < TAM_Y; i++) {
		for ( int j = 0; i < TAM_Y; i++) {
			mundo[i][j] = false;
		}
	}

	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */

	mundo[0][1] = true;
	mundo[1][2] = true;
	mundo[2][0] = true;
	mundo[2][1] = true;
	mundo[2][2] = true;

}

void gol_print(bool mundo[TAM_X][TAM_Y])
{
	// TODO: Imprimir el mundo por consola. Sugerencia:
	/*
	 *     . # . . . . . . . .
	 *     . . # . . . . . . .
	 *     # # # . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 */

	for ( int i = 0; i < TAM_X; i++ ) {
		for ( int j = 0; j < TAM_Y; j++ ) {
			printf("%c ", mundo[i][j] ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(bool mundo1[][TAM_Y], bool mundo2[][TAM_Y])
{
	/*
	 * TODO:
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */

	int count = 0;

	for (int i = 0; i < TAM_X; i++ ) {
        for (int j = 0; j < TAM_Y; j++ ) {
			count += gol_count_neighbors(mundo1, i, j);
			printf("count es %d\n", count);
		}
	}

}

int gol_count_neighbors(bool mundo[][TAM_Y], int x, int y)
{
	// Devuelve el número de vecinos
	int count = 0;
	const int coords[8][2] = {
		{-1, -1}, {0, -1}, {1, -1},
		{-1,  0},          {1,  0},
		{-1,  1}, {0,  1}, {1,  1}
	};

	for ( int i = 0; i < 8; i++ ) {
		count += gol_get_cell(mundo,
			y + coords[i][1],
			x + coords[i][0]
		);
		printf("y es %d\n", y + coords[i][1]);
		printf("x es %d\n", x + coords[i][0]);	
	}

	return count;
}

bool gol_get_cell(bool mundo[][TAM_Y], int x, int y)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */

	//printf("mundo es %d\n", mundo[x][y]);
	// printf("x es %d\n", x);
	// printf("y es %d\n", y);

	return mundo[x][y];
}

void gol_copy(bool mundo1, bool mundo2)
{
	// TODO: copia el mundo segundo mundo sobre el primero
}
