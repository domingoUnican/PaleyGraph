#include <stdio.h>
#include "cliquer.h"


static int Number = 0;
static boolean print_clique(set_t s, graph_t *g, clique_options *opts);

static boolean print_clique(set_t s, graph_t *g, clique_options *opts) {
  if (set_return_next(s,0) == 1)
    {
      printf("New clique found:\n");
      set_print(s);
      printf("*****\n");
      Number++;
    }
  return TRUE;
}

/* Function for determining wether the substraction of two numbers is an square */
boolean is_square_mod_m(int c1, int c2, int m) {
  int number = (m + c1-c2)%m ;
  int temp  = 0;
  for (int i=1; i<m; i++)
    {
      temp = (i*i)%m;
      if (temp == number || temp == m-number)
	{
	return FALSE;
	}
    }
  return TRUE;
}
int main(int argc, char *argv[]) {
    int i, j;
    int exponent, modulo;
    int order;
    graph_t *g;
	
    if (argc!=3) {
        fprintf(stderr,"%s <exponent> <modulo>\n",argv[0]);
        return 1;
    }
    exponent = atoi(argv[1]);
    modulo = atoi(argv[2]);
    /* no timer */
    //clique_default_options->time_function = NULL; 

    order = modulo;
    g = graph_new(order);
    for (i = 1; i < order; i++)
        for (j = i+1; j < order; j++)
	  if(is_square_mod_m(i,j,modulo))
	    {
	      GRAPH_ADD_EDGE(g,i,j);
	    }
    clique_default_options->output=stderr;
    clique_default_options->user_function = print_clique;
    int number_cliques = clique_find_all(g,0,0,TRUE,clique_default_options);
    printf("Number of Paley set containing 1:%d\n",Number);
    printf("Total number of Paley set:%d\n",number_cliques);
    return 0;
}
