#include<stdio.h>
#include "cliquer.h"
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



int main(int argc, char *argv[]) 
{

   FILE* stream  = fopen("previous_calculus.txt", "r");
   char line[100];
   int modulo, result,i,j,order;
   graph_t *g;
   for (int i0 = 0; i0 < 10; i0++)
     {
       fgets(line, 100, stream);
       sscanf (line, "%d,%d", &modulo, &result);
       clique_default_options->time_function = NULL; 
       order = modulo;
       g = graph_new(modulo);
       for (i = 1; i < order; i++)
	 for (j = i+1; j < order; j++)
	   if(!is_square_mod_m(i,j,2,modulo))
	     {
	       GRAPH_ADD_EDGE(g,i,j);
	     }
       clique_default_options->output=stderr;
       set_t s=clique_find_single(g,0,0,FALSE,NULL);
       if (result == set_size(s))
	 {
	   printf("Previous calculations for modulo %d  gives %d and with our algorithm %d\n", modulo, result, set_size(s));
	 }
       else
	 {
	   printf("The algorithm is wrong for %d, %d\n",modulo, set_size(s));
	   return 0;
	 }
     }
  fclose(stream);

}

