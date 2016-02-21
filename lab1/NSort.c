#include "NSort.h"
#include <stdint.h>
#include <stdio.h>

void ISort(int32_t *array, int size)
{
	for (int i = 1; i < size; i++)
    {
       	int32_t temp = array[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[j] < temp)
                break;

            array[j + 1] = array[j];
            array[j] = temp;
        }
        for (int k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
        }
    	printf("\n");
    }
}