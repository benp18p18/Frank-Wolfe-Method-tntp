#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "exact_trips.h"


/*int main()
{
	FILE *f;
	char* trips[NUM_ZONE][NUM_ZONE];
	f = fopen("ChicagoSketch_trips.tntp", "r");
	trips_find(f, trips);

	fclose(f);
}*/


void trips_find(fp2, trips)
FILE *fp2;
char *trips[NUM_ZONE][NUM_ZONE];
{

	int size = 3500000;
	char *btrip;	
	btrip = (char *)malloc(sizeof(char *)*size);

	char *token;
	char *token2;
	char **breaker;
	
	breaker = (char **)malloc(sizeof(char *)*NUM_LINKS);
		
	
	fread(btrip, 35, 100000, fp2);
	
	token = strtok(btrip, ":");
	token = strtok(NULL, "g");
	
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

		if( i != 383)
		{
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
		
	} 



}	




	


