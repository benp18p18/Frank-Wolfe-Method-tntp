#ifndef SHORTEST_PATH
#define SHORTEST_PATH
#include "defines.h"

void shortest_path(struct values *data, char ***network,double times[NUM_LINKS]);

void queue(int **L, double **L_value, int *p, double *l, int source, int *Q, struct values *data);

double tall_cal( double tall);

#endif
