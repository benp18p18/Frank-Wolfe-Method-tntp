#ifndef DEFINES
#define DEFINES

#define NUM_ZONE 387
#define NUM_NODE 933
#define NUM_LINKS 2950
#define DEGREE_MAX 10

struct values
{
	int p[NUM_ZONE][NUM_NODE];
	double l[NUM_ZONE][NUM_NODE];
};

#endif 
