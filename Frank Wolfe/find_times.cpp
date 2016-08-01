#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "find_times.h"

void find_times(double flows[], double times[], double **network)
{

int i;


for ( i = 0; i < NUM_LINKS; i++)
{
	times[i] = 0;
}

for ( i = 0; i < NUM_LINKS; i++)
{
	times[i] = network[4][i]*(1 + 0.15*pow((flows[i]/network[2][i]),4)) + network[3][i]*MILE_C;  
}



}


