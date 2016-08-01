#include <stdlib.h>
#include <stdio.h>
#include "q_sort.h"

int reset(double l[], int p[], int lenght)
{
int i;

for ( i = 0; i < lenght; i++)
{
	p[i] = p[i+1];
	l[i] = l[i+1];
}

p[lenght] = 0;
l[lenght] = 0;
lenght--;

return(lenght);
} 


int mover(double *l, int *p, int lenght, int point, double val_point)
{

int k, r;
lenght++;
for ( k = 0; k < lenght && val_point > l[k]; k++)
{	

}

for ( r = lenght-1; r >= k; r--)
{
	p[r+1] = p[r];
	l[r+1] = l[r];	
}
p[k] = point;
l[k] = val_point; 

return(lenght);

}
