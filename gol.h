#ifndef _GOL_H_
#define _GOL_H_

#define TAM_X 3
#define TAM_Y 3

void gol_init(bool mundo[][TAM_Y]);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundo1[][TAM_Y], bool mundo2[][TAM_Y]);
int gol_count_neighbors(bool mundo[][TAM_Y], int x, int y);
bool gol_get_cell(bool mundo[][TAM_Y], int x, int y);

#endif