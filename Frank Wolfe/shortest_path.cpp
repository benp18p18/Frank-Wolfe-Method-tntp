#include <iostream>
#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include "shortest_path.h"
#include "q_sort.h"

void shortest_path(int ** previous, double* times, int ** L, int ** L_spot)
{

double **L_value;
double *l;
int *p;

int i, j;



L_value = (double **)malloc(sizeof(double *)*NUM_NODE);
for ( i = 0; i < NUM_NODE; i++)
{
	L_value[i] = (double *)malloc(sizeof(double)*DEGREE_MAX);

}

l = (double *)malloc(sizeof(double)*NUM_NODE);
p = (int *)malloc(sizeof(int)*NUM_NODE);

for ( i = 0; i < NUM_NODE; i++)
{
	L_value[i][0] = 0;
	for ( j = 1; j < DEGREE_MAX; j++)
	{
		L_value[i][j] = 10000;

	}
	
}


for (i = 0; i < NUM_NODE; i++)
{
	for (j = 1; j < DEGREE_MAX; j++)
	{
			L_value[i][j] = times[L_spot[i][j]];
	}
}






int Q2[NUM_ZONE];
for (i = 0; i < NUM_ZONE; i++)
{
	Q2[i] = i + 1;
}

int Q_value;
int *Q;
Q = new int [sizeof(int)*NUM_NODE];

int w = 0;
for (i = 0; i < NUM_ZONE; i++)
{
	for (j = 0; j < NUM_NODE; j++)
	{
		Q[j] = j + 1;
	}


	for (w = 0; w < NUM_NODE; w++)
	{
    	  	 p[w] = 0;
      		 l[w] = 100000;

	}

	Q_value = Q2[i] - 1;
	printf("\r%d", i+1);
	fflush(stdout);
	queue(L, L_value, p, l, Q_value, Q, previous); 
	
}

printf("\rDone");
fflush(stdout);
free(L_value);
free(Q);
free(p);
free(l);
}

void queue(int **L, double **L_value, int *p, double *l, int source, int *Q, int ** previous) 
{ 

int i, j, kk; 
int q_value; 

int *qp = new int [sizeof(int)*NUM_NODE];
double *ql = new double [sizeof(double)*NUM_NODE]; 
int lenght = 0;

qp[0] = source;
ql[0] = 0.0;
l[source] = 0.0;
q_value = source;

for (kk = 0; lenght >= 0; kk++)
{

	for (j = 0; L[q_value][j] != 0; j++)
	{

			if (l[L[q_value][j]-1] > l[q_value] +  L_value[q_value][j])
			{
					l[L[q_value][j]-1] = l[q_value] + L_value[q_value][j];
					p[L[q_value][j]-1] = q_value + 1;
					lenght = mover(ql, qp, lenght, L[q_value][j], l[L[q_value][j]-1]);			
			}


	}
	
	Q[q_value] = 0;
		
	while( Q[q_value] == 0 && lenght >= 0)
        {
                lenght = reset(ql, qp, lenght);
                q_value = qp[0]-1;
        }

/*        for ( i = 0; i < lenght+1; i++)
        {
                printf("%d ", qp[i]);
        }
        printf("done \n");
*/

}



for(i = 0; i < NUM_NODE; i++)
{	
	previous[source][i] = p[i]; 
}

delete [] ql;
delete [] qp;

}

double tall_cal(double tall)
{

tall = tall*0.991;

return(tall);

}


