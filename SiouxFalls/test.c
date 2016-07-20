#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include <math.h>

long double test(flows, network)
double flows[NUM_LINKS];
char *network[9][NUM_LINKS];
{
long double z;
int i;
z = 0;

double A, B;


for ( i = 0; i < NUM_LINKS; i++)
{
	A = atof(network[4][i]);
	B = atof(network[4][i])*((0.15)/pow(atof(network[2][i]), 4));

	z += A*flows[i] + ((B/5)*pow(flows[i], 5)); 


} 

z = z/100000;
return(z);

};
