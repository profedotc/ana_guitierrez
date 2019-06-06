#ifndef _GOL_H_
#define _GOL_H_

#define TAM_X 3
#define TAM_Y 3

struct gol
{
  bool worlds[2][TAM_X][TAM_Y];
  bool current_world;
};

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
int gol_count_neighbors(struct gol *g, int x, int y);
bool gol_get_cell(struct gol *g, int x, int y);

#endif