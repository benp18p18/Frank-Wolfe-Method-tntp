#ifndef ALPHA_FIND
#define ALPHA_FIND
#include "defines.h"

double get_alpha(double **network, double tall, double dif_flows[],double old_flows[]);

void alpha_mode(double *old_flows, double *flows, double *dif_flows);

void alpha_sum(double *flows, double *old_flows, double *dif_flows, long double alpha);

#endif
