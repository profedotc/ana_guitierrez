#ifndef _GOL_H_
#define _GOL_H_

#define TAM_X 3
#define TAM_Y 3

struct gol
{
  bool **worlds[2];
};

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
bool gol_alloc(struct gol *g, int x, int y);
void gol_free(struct gol *g, int x);

#endif