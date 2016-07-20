#ifndef SHORTEST_PATH
#define SHORTEST_PATH
#include "defines.h"

void shortest_path(struct values *data, char *network[9][NUM_LINKS],double times[NUM_LINKS]);

void queue(int L[NUM_NODE][DEGREE_MAX], double L_value[NUM_NODE][DEGREE_MAX], int p[NUM_NODE], double l[NUM_NODE], int source, int Q[NUM_ZONE], struct values *data);

double tall_cal( double tall);

#endif
