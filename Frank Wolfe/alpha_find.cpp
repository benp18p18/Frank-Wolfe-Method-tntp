#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include <math.h>
#include "alpha_find.h"

double get_alpha(double**network, double tall, double *dif_flows, double *old_flows)
{
double alpha;
double r;
double x_l;
double x_r;
double z_l;
double z_r;
double k_l;
double k_r;
double a;
double b;

a = 0.0;
b = 1.0;
r = 0.618033;
x_l = (b - a)*(1 - r) + a;
x_r = (b - a)*r + a;


int i;

double B, A, C;


while (b - a >= 2*tall)
{

	z_l = 0;
	z_r = 0;

	for ( i  = 0; i < NUM_LINKS; i++)
	{
		B = (network[4][i]*((0.15)/pow(network[2][i], 4)));
		A = network[4][i];
		C = network[3][i]*MILE_C;
		k_l = old_flows[i] + (dif_flows[i]*x_l);
		k_r = old_flows[i] + (dif_flows[i]*x_r);
		z_l += (A*k_l) + (B/5)*pow(k_l, 5) + C*k_l ;
		z_r += (A*k_r) + (B/5)*pow(k_r, 5)+ C*k_l;
	}

	if (z_l <= z_r)
	{
		b = x_r;
		x_r = x_l;
		x_l = (b - a)*(1 - r) + a;
	}
	else
	{
		a = x_l;
		x_l = x_r;
		x_r = (b - a)*r + a;

	}
}

alpha = 0.5*(b + a);

return(alpha);

} 




void alpha_mode(double *flows, double *old_flows, double *dif_flows)
{
int i;
for ( i = 0; i < NUM_LINKS; i++)
{
	dif_flows[i] = 0;
	dif_flows[i] = flows[i] - old_flows[i];
	
}


}







void alpha_sum(double *flows, double *old_flows, double *dif_flows, long double alpha)
{
int i;

for ( i = 0 ; i < NUM_LINKS; i++)
{

	flows[i] = old_flows[i] + alpha*dif_flows[i];
}

}

