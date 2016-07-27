#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "int_links.h"

void int_links( double**network, int **L, int **L_spot)
{

int i, j;

for ( i = 0; i < NUM_NODE; i++)
{
        L[i][0] = i + 1;
        L_spot[i][0] = 0;

}

int k;
int counter;
counter = 1;
j = 0;
for (i = 0; i < NUM_NODE; i++)
{
	k = i + 1;
	
	
        	for (j = j; k == network[0][j] && k < NUM_NODE + 1; j++)
        	{
               
            	L_spot[i][counter] = j;
           	L[i][counter] = network[1][j] ;
            	counter++;
	        if ( j == NUM_LINKS - 2)
		{
			k = NUM_NODE + 2;
		}
		
        	}
	

/*printf("%d %d\n", j, atoi(network[0][j]));*/
counter = 1;
}



/*for ( i = 0; i < NUM_NODE; i++)
{
	for ( j = 0; j < DEGREE_MAX; j++)
	{
		printf("%d %d\t", L[i][j], L_spot[i][j]);

	}
printf("\n");



}*/


}







