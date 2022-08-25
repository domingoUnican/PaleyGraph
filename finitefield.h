#ifndef FINITE_H
#define FINITE_H

#include "cliquer.h"


int int_pow(int base, int exp, int modulo);
int gcd(int a, int b);
boolean is_square_mod_m(int c1, int c2, int r, int m);
int least_square_mod_m(int r, int m);
int custom_print(set_t s);
int custom_print_paley(set_t s);
int custom_print_copaley(set_t s, int exponent, int modulo);
boolean condicion_palley(int a, int b, int exponent, int modulo);
boolean condicion_copalley(int a, int b, int exponent, int modulo); 
boolean print_clique(set_t s, graph_t *g, clique_options *opts);
graph_t* construct_palley_graph(int modulo, int exponent);
graph_t* construct_copalley_graph(int modulo, int exponent);

#endif 
