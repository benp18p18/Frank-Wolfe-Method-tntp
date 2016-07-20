#include <string.h>
#include <stdio.h>
#include "defines.h"


void trips_find(FILE *, char *trips[NUM_ZONE][NUM_ZONE]);

/*int main()
{
	FILE *f;
	char* trips[NUM_ZONE][NUM_ZONE];
	f = fopen("SiouxFalls_trips.tntp", "r");
	trips_find(f, trips);
	printf("%s", trips[23][0]);
	fclose(f);
}*/


void trips_find(fp, trips)
FILE *fp;
char *trips[NUM_ZONE][NUM_ZONE];
{
	char btrip[100000];	
	char *token;
	char *breaker[NUM_ZONE];
	
	
	fread(btrip, 2, 100000, fp);
	
	token = strtok(btrip, "g");	
	
	int i;
	for(i = 0; i < NUM_ZONE; i++ )
	{
		token = strtok(NULL, "Origin\t");
		token = strtok(NULL, "Origin\t");
		breaker[i] = token;
	}
	 				
	int k;
	for(i = 0; i < NUM_ZONE; i++)
	{	 

							
		token = strtok(breaker[i], ":");
		
		for (k = 0; k < NUM_ZONE; k++)
		{	
				
			token = strtok(NULL, ";"); 
			trips[i][k] = token;
			token = strtok(NULL, ":");			 
			
		}
		

	} 



	

	
	

}	




	


