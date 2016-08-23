#ifndef SHORTEST_PATH
#define SHORTEST_PATH
#include "defines.h"

void shortest_path(int ** previous, double* times, int **L, int **L_spot);

void queue(int **L, double **L_value, int *p, double *l, int source, int *Q, int ** previous);

double tall_cal( double tall);

#endif
