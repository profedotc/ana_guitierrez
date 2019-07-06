#ifndef _GOL_H_
#define _GOL_H_

struct gol;

struct gol_options {
    bool usage;
    int width;
    int height;
};

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
struct main_params *config(int argc, char **argv);
struct gol *gol_alloc(int x, int y);
void gol_free(struct gol *g);

#endif