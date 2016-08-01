#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

void links_used(double **links, struct values *data, double **trips)
{
int i, j;
int g, k;
k = 0;


for ( i = 0; i < NUM_NODE; i++ )
{
	for ( j = 0; j < NUM_NODE; j++)
	{
		links[i][j] = 0;		
	
	}; 
	

}; 

for ( i = 0; i < NUM_ZONE; i++ )
{
	for ( j = 0; j < NUM_ZONE; j++ )
	{
		g = j;
		if ( trips[i][j] != 0)
		{	
			while ((*data).p[i][g] != 0)
			{
				k = g;
				g = (*data).p[i][g] - 1;
				links[g][k] += trips[i][j];
			}

		}
	}
	

}
}
