#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include "shortest_path.h"

void shortest_path(data, network, times)
struct values *data;
char *network[9][NUM_LINKS];
double times[NUM_LINKS];
{

int L[NUM_NODE][DEGREE_MAX];
double L_value[NUM_NODE][DEGREE_MAX];
double l[NUM_NODE];
int p[NUM_NODE];

int i, j;

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


/*for ( i = 0; i < NUM_NODE; i++)
{
	for( j = 0; j < 5; j++)
	{
		printf("%f\t", L_value[i][j]);
	}
	printf("\n");
}*/


int Q2[NUM_ZONE];
for (i = 0; i < NUM_ZONE; i++)
{
	Q2[i] = i + 1;
}

int Q_value;
int Q[NUM_NODE];
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
	queue(L, L_value, p, l, Q_value, Q, data); 
}


}

void queue(L, L_value, p, l, source, Q, data)
int L[NUM_NODE][DEGREE_MAX];
double L_value[NUM_NODE][DEGREE_MAX];
int p[NUM_NODE]; 
double l[NUM_NODE]; 
int source; 
int Q[NUM_NODE]; 
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

	

};


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


