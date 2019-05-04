#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 3
#define TAM_Y 3

void gol_init(bool mundo);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundo1, bool mundo2);
int gol_count_neighbors(bool mundo, int coordenadaX, int coordenadaY);
bool gol_get_cell(bool mundo, int coordenadaX, int coordenadaY);
void gol_copy(bool mundo1, bool mundo2);

int main()
{
	int i = 0;
	int j = 0;
	// TODO: Declara dos mundos

	// TODO: inicializa el mundo
	bool mundo1[TAM_X][TAM_Y] = {
		{0, 1, 0},
		{0, 1, 0},
		{0, 1, 0},
	};

	bool mundo2[TAM_X][TAM_Y];

	do {
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo

		gol_print(mundo1);

		// for ( int i = 0; i < TAM_X; i++ ) {
		// 	for ( int j = 0; j < TAM_Y; j++ ) {
		// 		gol_print(mundo1[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// TODO: Itera
		
	} while (getchar() != 'q');

	gol_init(mundo1);

	return EXIT_SUCCESS;
}

void gol_init(bool mundo)
{
	// TODO: Poner el mundo a false
	mundo = false;
	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */

	printf("%d\n", mundo);
	// mundo[TAM_X][TAM_Y] = {
	// 	{ 0, 1, 0},
	// 	{ 0, 0, 1},
	// 	{ 1, 1, 1},
	// };
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

void gol_step(bool mundo1, bool mundo2)
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
}

int gol_count_neighbors(bool mundo, int coordenadaX, int coordenadaY)
{
	// Devuelve el número de vecinos
}

bool gol_get_cell(bool mundo, int coordenadaX, int coordenadaY)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
}

void gol_copy(bool mundo1, bool mundo2)
{
	// TODO: copia el mundo segundo mundo sobre el primero
}
