#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "exact_network.h"

/*int main()
{
FILE *fp;
char *network[9][NUM_LINKS];

int i, j;
for (i = 0; i < 9; i++)
{
        for (j = 0; j < NUM_LINKS; j++)
        {
                network[i][j] = (char *)malloc(sizeof(char *));
        }
}





fp = fopen("ChicagoSketch_net.tntp", "r");

net_find(fp, network);


	for( i = 0; i < NUM_LINKS; i++)
	{
		printf("%s\n", network[0][i]);
	}

printf("ok");
fclose(fp);

return(0);
}*/ 


void net_find(fp1, network)
FILE *fp1;
char *network[9][NUM_LINKS];
{	
	int size = 600000;
	char *bnet;
	bnet = (char *)malloc(sizeof(char *)*size);	
		
	char *breaker;
	const char s[4] = "type";
	char *token;
	char **pointers;
	
	pointers = (char **)malloc(sizeof(char *)*NUM_LINKS);


	fread(bnet, 6, 100000, fp1);

	token = strtok(bnet, s);
  	while( token != NULL ) 
   	{
		breaker = token;
		token = strtok(NULL, s);		    		  
 	}	

	token = strtok(breaker,";");
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
		token = strtok(NULL, "\t");
		values[0] = token;		
		
		for (k = 1; k < 9; k++)
		{	
			token = strtok(NULL,  "\t");	
			values[k] = token;	
		};
				
		for (j = 0; j < 9; j++)
		{
			network[j][i] = values[j];
		}	
						
	}
		


}	


