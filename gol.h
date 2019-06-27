#ifndef _GOL_H_
#define _GOL_H_

#define GET_CELL(g, x, y) ( g->worlds[w][x * g->size_y + y] )

struct gol
{
  bool *worlds[2];
  int size_x;
  int size_y;
};

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
bool gol_alloc(struct gol *g, int x, int y);
void gol_free(struct gol *g);

#endif