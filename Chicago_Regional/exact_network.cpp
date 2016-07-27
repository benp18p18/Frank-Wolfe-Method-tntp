#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "exact_network.h"

/*int main()
{
FILE *fp1;
char *** network;

int i;

network = (char ***)malloc(sizeof(char **)*9);
	for ( i = 0; i < 9; i++)
        {
                network[i] = (char **)malloc(sizeof(char *)*NUM_LINKS);

        }


fp1 = fopen("ChicagoRegional_net.tntp", "r");

net_find(fp1, network);

printf("ok");
fclose(fp1);

return(0);
} */


void net_find(FILE *fp1, double **network)
{	
	int size = 2000000;
	char *bnet;
	bnet = (char *)malloc(sizeof(char *)*size);	
		
	char *breaker;
	const char s[5] = "type";
	char *token;
	char **pointers;
	
	pointers = (char **)malloc(sizeof(char *)*NUM_LINKS);


	fread(bnet, 10, 200000, fp1);

	token = strtok(bnet, s);
  	while( token != NULL ) 
   	{
		breaker = token;
		token = strtok(NULL, s);		    		  
 	}	

	token = strtok(breaker,";");
	token = strtok(NULL, ";");
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
	for(i = 0 ; i < NUM_LINKS; i++)
	{
		
		token = strtok(pointers[i], "\t");
		values[0] = token;		
		
		for (k = 1; k < 9; k++)
		{	
			token = strtok(NULL,  "\t");	
			values[k] = token;	
		};
				
		for (j = 0; j < 9; j++)
		{
			network[j][i] = atof(values[j]);
		}	
						
	}
		

}	


