#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines.h"


int NUM_ZONE;
int NUM_NODE;
int NUM_LINKS;


void var_set(FILE * fp3)
{
	
	char *bhead;
	
	bhead = (char *)malloc(sizeof(char) * 400);
	
	fread(bhead, 2, 200, fp3);

	char *token2;

	char *token3;

	int values[10];	

	token2 = strtok(bhead, "~");
	
	token3 = strtok(token2, ">");
	
	int n = 0;
	while( token3 != NULL)
	{ 
		token3 = strtok(NULL, "<");
		values[n] = atoi(token3);
		token3 = strtok(NULL, ">");
		n++;
	}

	NUM_ZONE = values[0];
	
	NUM_NODE = values[1];
	
	NUM_LINKS = values[3];
	
	












}
