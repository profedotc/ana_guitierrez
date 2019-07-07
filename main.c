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


int main(int argc, char **argv)
{	
	int i = 0;

	int usage = false;
	int width = 0;
	int height = 0;
	bool random = false;
	int rseed = 0;

	int option_index = 0;
	int c;

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
				usage = true;
				print_usage();
				exit(0);
				break;
			case 'w':
				width = strtol(optarg, NULL, 0);
				break;
			case 'h':
				height = strtol(optarg, NULL, 0);
				break;
			case 'r':
				random = true;
				if (optarg)
					rseed = strtol(optarg, NULL, 0);
				break;
			case '?':
				/* getopt_long imprime un mensaje de error*/
				break;
			default:
				printf("Error\n");
				exit(EXIT_FAILURE);
		}
	}

	for (int i = optind; i < argc; i++)
		printf("Argumento desconocido: \"%s\"\n", argv[i]);

	struct gol *g;
	g = gol_alloc(width, height);

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

