#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "exact_trips.h"


/*int main()
{
	FILE *f2;
	
	int k;	

	double ** trips;
	
	trips = (double **)malloc(sizeof(double *)*NUM_ZONE);
	for ( k = 0; k < NUM_NODE; k++)
	{
        	trips[k] = (double *)malloc(sizeof(double)*NUM_ZONE);

	}	
		
	f2 = fopen("SiouxFalls_trips.tntp", "r");


	trips_find(f2, trips);

	fclose(f2);
	printf("ok");
	return(0);
}*/


void trips_find(FILE *fp2, double ** trips)
{

	int size = 500000000;
	char *btrip;	
	btrip = (char *)malloc(sizeof(char )*size);

	char *token;
	char *token2;
	char **breaker;
	
	breaker = (char **)malloc(sizeof(char *)*NUM_LINKS);
		
	
	fread(btrip, 50, 10000000, fp2);
	
	token = strtok(btrip, "g");
	token = strtok(NULL, "\n");
	int i, j;
	for(i = 0; token != NULL; i++ )
	{
		token = strtok(NULL, "g");
		breaker[i] = token;
		token = strtok(NULL, "\n");
	}


	for ( i = 0; i < NUM_ZONE; i++)
	{
		for ( j = 0; j < NUM_ZONE; j++)
		{
			trips[i][j] = 0.0;

		}	

	}	

	for(i = 0; breaker[i] != NULL; i++)
	{	 

							
		
                token = strtok(breaker[i], ":");

			while (token != NULL)
			{
				token2 = token;
				token = strtok(NULL, ";"); 
				if ( atoi(token2)-1 != -1)
				{
					trips[i][atoi(token2)-1] = atof(token);
				}
				token = strtok(NULL, ":");
		}
		
	} 


/*for (j = 0; j < NUM_ZONE; j++)
{
	printf("%d\n\n", j+1);
	for ( i = 0; i < NUM_ZONE; i++)
	{
		printf("%f\t",trips[j][i]);
	
	}
printf("\n\n");
}
*/

free(btrip);
}	




	


