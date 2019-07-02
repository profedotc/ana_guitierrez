#ifndef _GOL_H_
#define _GOL_H_

struct gol;

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
struct gol *gol_alloc(int x, int y);
void gol_free(struct gol *g);

#endif