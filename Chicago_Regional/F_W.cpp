#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "defines.h"
#include "exact_network.h"
#include "exact_trips.h"
#include "shortest_path.h"
#include "links_used.h"
#include "find_flows.h"
#include "find_times.h"
#include "alpha_find.h"
#include "test.h"
#include "int_links.h"



int main()
{
printf("Enter Number of Runs: ");
char kk[20];
scanf("%s", kk);
printf("\n");

clock_t begin = clock();

FILE *fp1;
FILE *fp2;

int i, j;

double ** network;
network = (double **)malloc(sizeof(double *)*9);
        for ( i = 0; i < 9; i++)
        {
                network[i] = (double *)malloc(sizeof(double)*NUM_LINKS);

        }

double ** trips;
trips = (double **)malloc(sizeof(double *)*NUM_ZONE);
for ( i = 0; i < NUM_NODE; i++)
{
	trips[i] = (double *)malloc(sizeof(double)*NUM_ZONE);

}

struct values *data = (struct values*)malloc(sizeof(struct values));
(*data).l = (double **)malloc(sizeof(double)*NUM_ZONE);
(*data).p = (int **) malloc(sizeof(int *)*NUM_ZONE);
for ( i = 0; i < NUM_NODE; i++)
{
	(*data).l[i] = (double *)malloc(sizeof(double)*NUM_NODE);
	(*data).p[i] = (int *)malloc(sizeof(int)*NUM_NODE);

}

fp1 = fopen("ChicagoRegional_net.tntp", "r"); 
fp2 = fopen("ChicagoRegional_trips.tntp", "r");

net_find(fp1, network);
trips_find(fp2, trips);

int ** L;
int ** L_spot;

L = (int **)malloc(sizeof(int *)*NUM_NODE); 
L_spot = (int **)malloc(sizeof(int *)*NUM_NODE); 
for ( i = 0; i < NUM_NODE; i++) 
{

        L[i] = (int *)malloc(sizeof(int )*DEGREE_MAX);
        L_spot[i] = (int *)malloc(sizeof(int)*DEGREE_MAX);

}

int_links(network, L, L_spot);

double times[NUM_LINKS];

for ( i = 0; i < NUM_LINKS; i++)
{
	times[i] = network[4][i] + network[3][i]*MILE_C;
}

shortest_path(data, times, L, L_spot);

double ** links;

links = (double **)malloc(sizeof(double *)*NUM_NODE);
        
for ( i = 0; i < NUM_NODE; i++)
{
	links[i] = (double *)malloc(sizeof(double )*NUM_NODE);
	
}

links_used(links, data, trips);

double flows[NUM_LINKS];

find_flows(links, flows, network);

find_times(flows, times, network);

double old_flows[NUM_LINKS];
double dif_flows[NUM_LINKS];
double alpha;

for ( i = 0; i < NUM_LINKS; i++)
{
	old_flows[i] = flows[i];
}


long double z;

z = test(old_flows, network);

printf("\rInt Obj: %Lf\n\n", z);

long double z_save;

z_save = 100000000;

double tall;
tall = 0.1;

for ( i = 0; i < atoi(kk) ; i++)
{

	shortest_path(data, times, L, L_spot);

	links_used(links, data, trips);

	find_flows(links, flows, network);

	alpha_mode(flows, old_flows, dif_flows);

	alpha = get_alpha(network, 0.00001, dif_flows, old_flows);


	alpha_sum(flows, old_flows, dif_flows, alpha);

	for ( j = 0; j < NUM_LINKS; j++)
	{
        	old_flows[j] = flows[j];
	}

	z = test(old_flows, network);

	if ( z_save <= z)
	{

		tall = tall_cal(tall);
	}

	z_save = z;
	
	find_times(flows, times, network);

	printf("\rObj: %0.10Lf\n", z);

	printf("Alpha Value: %0.10f\t", alpha);

	printf("Count : %d\n", i+1);

	printf("Tall : %0.10f\n\n", tall);

}


FILE * fp;

fp = fopen("data.txt", "w");


fprintf(fp,"\nint\t   end\t");
fprintf(fp,"   flow\t\t");
fprintf(fp,"cost\n\n");


for ( i = 0; i < NUM_LINKS; i++)
{
	fprintf(fp,"%d\t", (int)network[0][i]);
	fprintf(fp,"%d\t", (int)network[1][i]);
        fprintf(fp,"%f\t", flows[i]);
	fprintf(fp,"%f;\t\n", times[i]);
}

fclose(fp);
fclose(fp1);
fclose(fp2);

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("\nCPU Time: %f\n\n", time_spent);

free(data);
free(links);


return(0);
}
