#include<stdio.h>
#include "finitefield.h"


int main(int argc, char *argv[]) 
{

   FILE* stream  = fopen("previous_calculus.txt", "r");
   char line[100];
   int modulo, result, our;
   graph_t *g;
   for (int i0 = 0; i0 < 50; i0++)
     {
       fgets(line, 100, stream);
       sscanf (line, "%d,%d", &modulo, &result);
       clique_default_options->time_function = NULL; 
       g = construct_palley_graph(modulo, 2);
       clique_default_options->output=stderr;
       set_t s=clique_find_single(g,0,0,FALSE,NULL);
       our = custom_print_paley(s);
       if (result == our)
	 {
	   printf("Previous calculations for modulo %d  gives %d and with our algorithm %d\n", modulo, result, our);
	 }
       else
	 {
	   printf("The algorithm is wrong for %d, %d and the correct is %d \n",modulo,our,result);
	 }
     }
  fclose(stream);

}

