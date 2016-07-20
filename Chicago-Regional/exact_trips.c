#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "exact_trips.h"


/*int main()
{
	FILE *f2;
	
	

	char *** trips;
	
	trips = (char ***)malloc(sizeof(char **)*NUM_ZONE);
	for ( i = 0; i < NUM_NODE; i++)
	{
        	trips[i] = (char **)malloc(sizeof(char *)*NUM_ZONE);

	}	
		


	f2 = fopen("ChicagoRegional_trips.tntp", "r");


	trips_find(f2, trips);

	fclose(f2);
	printf("ok");
	return(0);
}*/


void trips_find(fp2, trips)
FILE *fp2;
char *** trips;
{

	int size = 500000000;
	char *btrip;	
	btrip = (char *)malloc(sizeof(char *)*size);

	char *token;
	char *token2;
	char **breaker;
	
	breaker = (char **)malloc(sizeof(char *)*NUM_LINKS);
		
	
	fread(btrip, 50, 10000000, fp2);
	
	token = strtok(btrip, "g");
	
	int i, j;
	for(i = 0; i < NUM_ZONE; i++ )
	{
		token = strtok(NULL, "Origin\t");
		breaker[i] = token;
	}
		 				

	for ( i = 0; i < NUM_ZONE; i++)
	{
		for ( j = 0; j < NUM_ZONE; j++)
		{
			trips[i][j] = "0.00";

		}	

	}	

	for(i = 0; i < NUM_ZONE; i++)
	{	 

							
		token = strtok(breaker[i], "\n");
		
                token = strtok(NULL, ":");

			while (token != NULL)
			{
				token2 = token;
				token = strtok(NULL, ";"); 
				if ( atoi(token2)-1 != -1)
				{
					trips[i][atoi(token2)-1] = token;
				}
				token = strtok(NULL, ":");
		}
		
	} 

/*	for ( i = 0; i < NUM_ZONE; i++)
	{
		printf("count %d %s\n", i, trips[0][i]);
	
	}
*/
}	




	


