#include "finitefield.h"

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

// Returns the gcd of a and b if a>b
int gcd(int a, int b){
  int temp = 0;
  while (b > 0)
    {
      a = a - b;
      if (a < b)
	{
	  a = temp;
	  a = b;
	  b = temp;
	}
    }
  return a;
}


/* Function for determining wether the substraction of two numbers is an rth power */
boolean is_square_mod_m(int c1, int c2, int r, int m) {
  int number = (m + c1-c2)%m ;
  int temp  = 0;
  for (int i=0; i<m; i++)
    {
      temp = int_pow(i,r,m);
      if (temp == number || temp == m-number)
	{
	return TRUE;
	}
    }
  return FALSE;
}

int least_square_mod_m(int r, int m)
{
  int j = 1; 
  while(is_square_mod_m(j,0,r,m))
    {
      j = j + 1;
    }
  return j;
}

int custom_print(set_t s)
{
  int i = set_return_next(s,-1);
  printf("The clique has size: %d\n", set_size(s));
  printf("The clique is:\n");
  while (i >= 0)
    {
      printf("%d ",i);
      i=set_return_next(s,i);

    }
  printf("\n");
  return set_size(s);
}

int custom_print_paley(set_t s)
{
  if (set_size(s) == 1)
    {
      printf("The clique has size: 2\nThe clique is:\n0 1\n");
      return 2;
    }
  SET_ADD_ELEMENT(s, 0);
  SET_ADD_ELEMENT(s, 1);
  return custom_print(s);

}
int custom_print_copaley(set_t s, int exponent, int modulo)
{
  int r = least_square_mod_m(exponent, modulo);
  if (set_size(s) == 1)
    {
      printf("The clique has size: 2\nThe clique is:\n0 %d\n",r);
      return 2;
    }
  SET_ADD_ELEMENT(s, 0);
  printf("least square %d\n",least_square_mod_m(exponent, modulo));
  SET_ADD_ELEMENT(s, r);
  return custom_print(s);
}


boolean print_clique(set_t s, graph_t *g, clique_options *opts) {
  if (set_return_next(s,0) == 1)
    {
      printf("New clique found:\n");
      custom_print(s);
      printf("*****\n");
    }
  return TRUE;
}


boolean condicion_palley(int a, int b, int exponent, int modulo){
  return (is_square_mod_m(a,b,exponent,modulo) &&
	  is_square_mod_m(a,0,exponent,modulo) &&
	  is_square_mod_m(a,1,exponent,modulo) &&
	  is_square_mod_m(b,0,exponent,modulo) &&
	  is_square_mod_m(b,1,exponent,modulo) );
	  
}

boolean condicion_copalley(int a, int b, int exponent, int modulo){
  int j = least_square_mod_m(exponent, modulo); 
  return (!is_square_mod_m(a,b,exponent,modulo) &&
	  !is_square_mod_m(a,0,exponent,modulo) &&
	  !is_square_mod_m(a,j,exponent,modulo) &&
	  !is_square_mod_m(b,0,exponent,modulo) &&
	  !is_square_mod_m(b,j,exponent,modulo) );
	  
}

graph_t* construct_palley_graph(int modulo, int exponent){
  graph_t *g;
  int i,j;
  g = graph_new(modulo);
  for (i = 1; i < modulo; i++)
    for (j = i+1; j < modulo; j++)
      if(condicion_palley(i,j,exponent,modulo))
	{
	  GRAPH_ADD_EDGE(g,i,j);
	}
  return g;
}

graph_t* construct_copalley_graph(int modulo, int exponent){
  graph_t *g;
  int i,j;
  g = graph_new(modulo);
  for (i = 1; i < modulo; i++)
    for (j = i+1; j < modulo; j++)
      if(condicion_copalley(i,j,exponent,modulo))
	{
	  GRAPH_ADD_EDGE(g,i,j);
	}
  return g;
}
