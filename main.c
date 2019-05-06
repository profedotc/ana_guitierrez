#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 3
#define TAM_Y 3

void gol_init(bool mundo[][TAM_Y]);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundo1, bool mundo2);
int gol_count_neighbors(bool mundo, int coordenadaX, int coordenadaY);
bool gol_get_cell(bool mundo, int coordenadaX, int coordenadaY);
void gol_copy(bool mundo1, bool mundo2);

int main()
{
	int i = 0;
	// TODO: Declara dos mundos
	bool mundo1[TAM_X][TAM_Y];
	bool mundo2;

	// TODO: inicializa el mundo
	gol_init(mundo1);

	do {
		printf("\033cIteration %d\n", i++);
		
		// TODO: Imprime el mundo
		gol_print(mundo1);

		// TODO: Itera
		
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
	mundo[2][1] = true;

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
