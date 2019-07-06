#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include "gol.h"


static void print_usage() {
	printf("-u, --usage: Prints this help message");
	printf("-w, --width: Width of the world");
	printf("-h, --height: Height of the world");
}

static bool check_params(struct gol_options *p)
{
	bool isOk = true;

	if (p->usage)
		return true;

	isOk &= p->width > 0;
	isOk &= p->height > 0;

	return isOk;
}


int main(int argc, char *argv[])
{
	int i = 0;
	struct gol *g;
	struct gol_options params;

	int option = 0;
	int c;
    int usage = 1, width = -1, height = -1;

	static struct option long_options [] =
	{
		{"usage" , no_argument , 0, 'u'},
		{"width" , required_argument , 0, 'w'},
		{"height" , required_argument, 0, 'h'},
		{ 0 , 0 , 0 , 0}
	};

	while ((c = getopt_long(argc, argv, "uw:h:", long_options, 
            &option)) != -1) { {
        switch (option) {
             case 'u': usage = 1;
                 break;
             case 'w': width = strtol(optarg, NULL, 0);
                 break;
             case 'h': height = strtol(optarg, NULL, 0); 
                 break;
             default: print_usage(); 
                 exit(EXIT_FAILURE);
        }
    }
    if (width == -1 || height ==-1) {
        print_usage();
        exit(EXIT_FAILURE);
    }
	//return check_params(p);


	// if (!parse_params(&params, argc, argv)) {
	// 	printf("No se pudo asignar parámetros\n");
	// 	print_usage(char *argv0);
	// 	return EXIT_FAILURE;
	// } else if (params.usage) {
	// 	print_usage(char *argv0);
	// 	return EXIT_SUCCESS;
	// }

	if ( width > 0 && height > 0) {
		printf("Tutto buono. Width es %d", width);
		printf(" y height es %d", height, "\n");
	}
	
	g = gol_alloc(10, 15);

	if (!g) {
		printf("No se pudo reservar memoria para mundo\n");
		return EXIT_FAILURE;
    }

	gol_init(g);

	do {
		printf("\033cIteration %d\n", i++);

		gol_print(g);

		printf("\n\n");
		gol_step(g);

	} while (getchar() != 'q');

	gol_free(g);

	return EXIT_SUCCESS;
}
