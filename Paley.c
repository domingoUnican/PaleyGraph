#include <stdio.h>
#include "finitefield.h"


int main(int argc, char *argv[]) {
    int exponent, modulo;
    graph_t *g;
	
    if (argc<3) {
        fprintf(stderr,"%s <exponent> <modulos>\n",argv[0]);
        return 1;
    }
    exponent = atoi(argv[1]);
    for(int num_modulos = 2; num_modulos<argc; num_modulos++)
      {
	modulo = atoi(argv[num_modulos]);
	printf("Search for Paley graph of order %d\n", modulo);
	clique_default_options->time_function = NULL; 
	g = construct_palley_graph(modulo, exponent);
	clique_default_options->output=stderr;
	clique_default_options->user_function = print_clique;
	set_t s=clique_find_single(g,0,0,FALSE,NULL);
	custom_print_paley(s);
      }
    
    return 0;
}
