#include <string.h>
#include <stdio.h>
#include "defines.h"

void net_find(FILE *, char *network[9][NUM_LINKS]);

/*int main()
{
FILE *fp;
char *network[9][NUM_LINKS];
fp = fopen("SiouxFalls_net.tntp", "r");

net_find(fp, network);

int i;

	for( i = 0; i < NUM_LINKS; i++)
	{
		printf("%s\n", network[2][i]);
	};

fclose(fp);

} */


void net_find(fp, network)
FILE *fp;
char *network[9][NUM_LINKS];
{	
	char bnet[200000];	
	char *breaker;
	const char s[4] = "Type";
	char *token;
	char *pointers[NUM_LINKS];
	
	fread(bnet, 10, 1000, fp);

	token = strtok(bnet, s);
  	while( token != NULL ) 
   	{
		breaker = token;
		token = strtok(NULL, s);		    		
   	};	

	token = strtok(breaker, ";");
	int n = 0;
	while (token != NULL)
	{		
		token = strtok(NULL, ";");
		pointers[n] = token;
		n++;
	};		

	int i;
	char *values[10];
	int k;
	int j;
	for(i = 0 ; i < NUM_LINKS; i++)
	{
		
		token=strtok(pointers[i], "\t");
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
	};
		
	

}	


