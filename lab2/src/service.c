#include "service.h"
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

/*
	string compare:
	return 1, if str1 > str2,
	return -1, if str1 < str2,
	return 0, if str1 and str2 are equal
*/
short int scmp(char *str1, char *str2)
{
	int i;
	short int flg = 0;
	for(i=0; (str1[i]==str2[i]) && str1[i]!='\0' && str2[i]!='\0'; i++);
	if(str1[i] < str2[i]) 
	{
		flg = -1;
	}
	else if (str1[i] > str2[i])
	{
		flg = 1;
	}
	return flg;
}