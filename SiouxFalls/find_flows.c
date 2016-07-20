#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

void find_flows(links, flows, network)
double **links;
double flows[NUM_LINKS];
char *network[9][NUM_LINKS];
{
int i, k;

for ( i = 0; i < NUM_LINKS; i++)
{
	flows[i] = 0;
};

k = 0;


for ( i = 0; i < NUM_LINKS; i++)
{


flows[k] = links[atoi(network[0][i])-1][atoi(network[1][i])-1];
k++;

};






}
