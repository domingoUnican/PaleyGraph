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


int int_pow(int base, int exp, int modulo)
{
    int result = 1;
    while (exp)
    {
        if (exp % 2)
	  {
	    result *= base;
	    result = result % modulo;
	  }
        exp = exp >> 1;
        base *= base;
	base = base % modulo;
    }
    return result;
}

/* Function for determining wether the substraction of two numbers is an rth power */
boolean is_square_mod_m(int c1, int c2, int r, int m) {
  int number = (m + c1-c2)%m ;
  int temp  = 0;
  for (int i=1; i<m; i++)
    {
      temp = int_pow(i,r,m);
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
	order = modulo;
	g = graph_new(order);
	for (i = 1; i < order; i++)
	  for (j = i+1; j < order; j++)
	    if(is_square_mod_m(i,j,exponent,modulo))
	      {
		GRAPH_ADD_EDGE(g,i,j);
	      }
	clique_default_options->output=stderr;
	clique_default_options->user_function = print_clique;
	set_t s=clique_find_single(g,0,0,FALSE,NULL);
	printf("first one\n");
	set_print(s);
	/***********************************************************************************/
	/* int number_cliques = clique_find_all(g,0,0,TRUE,clique_default_options);	   */
	/***********************************************************************************/
	/*******************************************************************/
	/* printf("Number of Paley set containing 1:%d\n",Number);	   */
	/* printf("Total number of Paley set:%d\n",number_cliques);	   */
	/* printf("%%%%%%%%%%%%%%%%%%%%%%%%%%\n");			   */
	/*******************************************************************/
	/**********************************************************/
	/* printf("El resultado es %d, %d, %d:\n",		  */
	/*        !is_square_mod_m(1,26,exponent, modulo),	  */
	/*        int_pow(13,45,181),				  */
	/*        int_pow(2,2,7));				  */
	/**********************************************************/
      }
    return 0;
}
