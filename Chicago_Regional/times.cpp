#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

void find_times(double flows[NUM_LINKS], double times[NUM_LINKS], double **network)
{

int i;


for ( i = 0; i < NUM_LINKS; i++)
{
	times[i] = 0;
};

for ( i = 0; i < NUM_LINKS; i++)
{

	times[i] = network[4][i]*( 1 + 0.15*(flows[i]/network[6][i])**4); 

};


}


