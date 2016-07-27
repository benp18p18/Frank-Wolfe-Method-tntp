#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

void find_flows(double **links, double flows[NUM_LINKS], double **network)
{
int i, k;

for ( i = 0; i < NUM_LINKS; i++)
{
	flows[i] = 0;
}

k = 0;


for ( i = 0; i < NUM_LINKS; i++)
{


	flows[k] = links[(int)network[0][i]-1][(int)network[1][i]-1];
	k++;

}






}
