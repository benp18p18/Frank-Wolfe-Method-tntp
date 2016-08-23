#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include <math.h>

long double test(double flows[], double **network)
{
long double z;
int i;
z = 0;

double A, B, C, D;


for ( i = 0; i < NUM_LINKS; i++)
{
	A = network[4][i];
	B = network[4][i]*(0.15);
	C = network[3][i]*MILE_C;
	D = network[8][i]*TOLL_C;

	z += A*flows[i] + ((B/(5*pow(network[2][i], 4)))*pow(flows[i], 5)) + C*flows[i] + D*flows[i]; 


} 

z = z;
return(z);

}
