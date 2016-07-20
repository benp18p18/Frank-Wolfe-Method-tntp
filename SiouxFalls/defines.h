#ifndef DEFINES
#define DEFINES

#define NUM_ZONE 24
#define NUM_NODE 24
#define NUM_LINKS 76
#define DEGREE_MAX 6

struct values
{
	int p[NUM_ZONE][NUM_NODE];
	double l[NUM_ZONE][NUM_NODE];
};

#endif 
