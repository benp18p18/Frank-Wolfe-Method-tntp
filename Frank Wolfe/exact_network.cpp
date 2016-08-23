#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "exact_network.h"

/*int main()
{
FILE *fp1;
double ** network;

int i;

network = (double **)malloc(sizeof(double *)*9);
	for ( i = 0; i < 9; i++)
        {
                network[i] = (double *)malloc(sizeof(double)*NUM_LINKS);

        }


fp1 = fopen("SiouxFalls_net.tntp", "r");

net_find(fp1, network);

printf("ok");
fclose(fp1);

return(0);
} */


void net_find(FILE *fp1, double **network)
{	
	int size = 2000000;
	char *bnet;
	bnet = new char  [sizeof(char )*size];	
		
	char *breaker = NULL;
	const char *s = "~";
	char *token;
	char **pointers;
	
	pointers = new char * [sizeof(char *)*NUM_LINKS];
	int h;
	for ( h = 0; h < NUM_LINKS; h++)
	{
		pointers[h] = new char [100];
	}
	

	fread(bnet, 10, 200000, fp1);

	token = strtok(bnet, s);
  	
	while( token != NULL ) 
   	{
		breaker = token;
		token = strtok(NULL, s);		    		  
	}	
	
	token = strtok(breaker,"\n");

	token = strtok(NULL, ";");
	int n = 0;
	pointers[n] = token;

	while (token != NULL)
	{		
		token = strtok(NULL, ";");
		n++;
		pointers[n] = token;
	}		

	int i;
	char *values[10];
	int k;
	int j;
	int k_value;
	for(i = 0 ; i < NUM_LINKS; i++)
	{
		token = strtok(pointers[i], "\t");
				
		if (atoi(pointers[i]) != 0 )
		{
			values[0] = token;		
			k_value = 1;
		}
		else
		{
			k_value = 0;
		}

		for (k = k_value; k < 9 ; k++)
		{	
			token = strtok(NULL,  "\t");	
			values[k] = token;	
		}
				
		for (j = 0; j < 9 ; j++)
		{
			network[j][i] = atof(values[j]);
		}	
	}
/*for ( i = 0; i < 9; i++)
{
	printf("%f\n", network[i][0]);
	
}*/

delete [] bnet;


}	


