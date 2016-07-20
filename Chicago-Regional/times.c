#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

void find_times(flows, times, network)
double flows[NUM_LINKS];
double times[NUM_LINKS];
char ***network;
{

int i;


for ( i = 0; i < NUM_LINKS; i++)
{
	times[i] = 0;
};

for ( i = 0; i < NUM_LINKS; i++)
{

	times[i] = atof(network[4][i])*( 1 + 0.15*(flows[i]/atof(network[6][i]))**4); 

};


}


