#include <stdio.h>
#include <stdlib.h>
#include "average_excess.h"
#include "defines.h"

double average_excess(double * flows, double * all_or_not_flows, double * times){
double sum_times = 0;

int i;


for ( i = 0; i < NUM_LINKS; i++)
{
	sum_times += (flows[i] - all_or_not_flows[i])*times[i];

}


return(sum_times);

}

double total_flow(double ** trips){
double total = 0;

int i, j;

for ( i = 0; i < NUM_ZONE; i++)
{
	for ( j = 0; j < NUM_ZONE; j++)
	{
		total += trips[i][j];
	}

}



return(total);

}
