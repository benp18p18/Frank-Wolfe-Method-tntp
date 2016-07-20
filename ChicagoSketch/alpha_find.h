#ifndef ALPHA_FIND
#define ALPHA_FIND
#include "defines.h"

double get_alpha(char *network[9][NUM_LINKS], double tall, double dif_flows[NUM_LINKS],double old_flows[NUM_LINKS]);

void alpha_mode(double old_flows[NUM_LINKS], double flows[NUM_LINKS], double dif_flows[NUM_LINKS]);

void alpha_sum(double flows[NUM_LINKS], double old_flows[NUM_LINKS], double dif_flows[NUM_LINKS], long double alpha);

#endif
