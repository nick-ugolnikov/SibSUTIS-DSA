#include "Service.h"
#include <stdlib.h>
#include <sys/time.h>

int getrand(int min, int max) //Random function
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime() //Time generator
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}