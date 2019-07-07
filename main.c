#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"
#include <getopt.h>

static void print_usage() {
	printf("-u, --usage: Prints this help message\n");
	printf("-w, --width: Width of the world\n");
	printf("-h, --height: Height of the world\n");
}

bool random = false;
int rseed = 0;

int option_index = 0;
int c;

static bool parse_args(int argc, char *argv[], struct gol_options *gol_opt) {
	
	static struct option long_options [] =
	{
		{"usage" , no_argument , 0, 'u'},
		{"width" , required_argument , 0, 'w'},
		{"height" , required_argument, 0, 'h'},
		{"random" , optional_argument, 0, 'r'},
		{ 0 , 0 , 0 , 0}
	};

	while ((c = getopt_long(argc, argv, "uw:h:r::", long_options, 
		&option_index)) != -1) {
		switch (c) {
			case 'u':
				gol_opt->usage = true;
				break;
			case 'w':
				gol_opt->width = strtol(optarg, NULL, 0);
				break;
			case 'h':
				gol_opt->height = strtol(optarg, NULL, 0);
				break;
			case 'r':
				random = true;
				if (optarg)
					rseed = strtol(optarg, NULL, 0);
				break;
			case '?':
                printf("\nOpción no reconocida %s \n", optarg);
				break;
			default:
				printf("Error\n");
				exit(EXIT_FAILURE);
		}
	}

	for (int i = optind; i < argc; i++)
		printf("Argumento desconocido: \"%s\"\n", argv[i]);

	return 1;
};

int main(int argc, char *argv[])
{	
	int i = 0;

	struct gol_options gol_opt;
	gol_opt.usage = 0;

	if (parse_args(argc, argv, &gol_opt) ==! 1) {
        print_usage();
        return -1;
    }
    if (gol_opt.usage) {
        print_usage();
        return 0;
    }

	
	struct gol *g;
	g = gol_alloc(gol_opt.width, gol_opt.height);

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

