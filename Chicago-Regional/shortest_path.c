#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include "shortest_path.h"

void shortest_path(data, network, times)
struct values *data;
char ***network;
double times[NUM_LINKS];
{

int **L;
double **L_value;
double *l;
int *p;

int i, j;



L = (int **)malloc(sizeof(int *)*NUM_NODE);
L_value = (double **)malloc(sizeof(double *)*NUM_NODE);
for ( i = 0; i < NUM_NODE; i++)
{
	L[i] = (int *)malloc(sizeof(int )*DEGREE_MAX);
	L_value[i] = (double *)malloc(sizeof(double)*DEGREE_MAX);

}

l = (double *)malloc(sizeof(double)*NUM_NODE);
p = (int *)malloc(sizeof(int)*NUM_NODE);

for ( i = 0; i < NUM_NODE; i++)
{
	for ( j = 0; j < DEGREE_MAX; j++)
	{
		L_value[i][j] = 10000;
		L[i][j] = 0;	

	}

}

for ( i = 0; i < NUM_NODE; i++)
{
	L[i][0] = i + 1;
	L_value[i][0] = 0;

}

int k;
int counter;
counter = 1;
for (i = 0; i < NUM_NODE; i++)
{
	for (j = 0; j < NUM_LINKS; j++)
	{
		k = i + 1;		
		if (k == atoi(network[0][j]))
		{
			L_value[i][counter] = times[j];
			L[i][counter] = atoi(network[1][j]) ; 
			counter++;
		}		

	}
counter = 1;
}



int Q2[NUM_ZONE];
for (i = 0; i < NUM_ZONE; i++)
{
	Q2[i] = i + 1;
}

int Q_value;
int *Q;
Q = (int*)malloc(sizeof(int)*NUM_NODE);

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
	printf("%d\n", i);
	queue(L, L_value, p, l, Q_value, Q, data); 
}

free(L_value);
free(L);
free(Q);
free(p);
free(l);
}

void queue(L, L_value, p, l, source, Q, data) 
int **L; 
double **L_value; 
int *p; 
double *l; 
int source; 
int *Q; 
struct values *data; 
{ 
double min_value; 
int i, j, k; 
int q_value; 
int location;

l[source] = 0;

for (k = 0; k < NUM_NODE; k++)
{
	min_value = 100000;
	for (i = 0; i < NUM_NODE; i++)
	{
		if ( Q[i] != 0)
		{
			if ( l[i] < min_value)
			{
				q_value = i;
				location = i;
				min_value = l[Q[i]-1];
			}
		}

	} 


	for (j = 0; j < DEGREE_MAX; j++)
	{
		if ( L[q_value][j] != 0)
		{	

			if (l[L[q_value][j]-1] > l[q_value] +  L_value[q_value][j])
				{
					l[L[q_value][j]-1] = l[q_value] + L_value[q_value][j];
					p[L[q_value][j]-1] = q_value + 1;
				}
		}
	}
	
	Q[location] = 0;

	

}


for(i = 0; i < NUM_NODE; i++)
{	
	(*data).l[source][i] = l[i];
	(*data).p[source][i] = p[i]; 
}

}

double tall_cal(tall)
double tall;
{

tall = tall*0.991;

return(tall);

}


