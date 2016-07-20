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


int main()
{
printf("Enter Number of Runs: ");
char kk[20];
scanf("%s", kk);
printf("\n");

clock_t begin = clock();

static FILE *fp1;
static FILE *fp2;


char *network[9][NUM_LINKS]; 



int i, j;
for (i = 0; i < 9; i++)
{
	for (j = 0; j < NUM_LINKS; j++)
	{
		network[i][j] = (char *)malloc(sizeof(char *));
	}
}

char *trips[NUM_ZONE][NUM_ZONE];

for (i = 0; i < NUM_ZONE; i++)
{
        for (j = 0; j < NUM_ZONE; j++)
        {
                trips[i][j] = (char *)malloc(sizeof(char *));
        }
}

struct values *data = (struct values*)malloc(sizeof(struct values));

fp1 = fopen("ChicagoSketch_net.tntp", "r"); 
fp2 = fopen("ChicagoSketch_trips.tntp", "r");

net_find(fp1, network);
trips_find(fp2, trips);


/*for ( i = 0; i < NUM_ZONE; i++)
{
	printf("%s\t", trips[0][i]);
}*/

/*double summer = 0;

int sum1, sum2;

for (sum1 = 0; sum1 < NUM_ZONE; sum1++)
{
	for( sum2 = 0; sum2 < NUM_ZONE; sum2++)
	{
		summer += atof(trips[sum1][sum2]);
		printf("%s\t", trips[sum1][sum2]);
	}
	printf("\n\n");

}
printf("%f sum\n\n", summer);
*/

double times[NUM_LINKS];

for ( i = 0; i < NUM_LINKS; i++)
{
	times[i] = atof(network[4][i]);
}
shortest_path(data, network, times);

double ** links;

links = (double **)malloc(sizeof(double *)*NUM_NODE);
        
for ( i = 0; i < NUM_NODE; i++)
{
	links[i] = (double *)malloc(sizeof(double )*NUM_NODE);
	
}

links_used(links, trips, data);

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

printf("\n\n");
long double z;

z = test(old_flows, network);

printf("Int Obj: %Lf\n\n", z);

long double z_save;

z_save = 100000000;

double tall;
tall = 0.1;

for ( i = 0; i < atoi(kk) ; i++)
{

	shortest_path(data, network, times);

	links_used(links, trips, data);

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

	printf("Obj: %0.10Lf\n", z);

	printf("Alpha Value: %0.10f\t", alpha);

	printf("Count : %d\n", i+1);

	printf("Tall : %0.10f\n\n", tall);

}

printf("\nint\tend\t");
printf("flow\t\t");
printf("cost\n");


for ( i = 0; i < NUM_LINKS; i++)
{
	printf("%s\t", network[0][i]);
	printf("%s\t", network[1][i]);
        printf("%f\t", flows[i]);
	printf("%f\n", times[i]);
}



clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


printf("\nCPU Time: %f\n\n", time_spent);

free(data);
free(links);


return(0);
}
