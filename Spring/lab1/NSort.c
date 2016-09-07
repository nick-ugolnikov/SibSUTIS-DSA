#include "NSort.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Implementation of sorting algorithms

void CountingSort(uint32_t *array, int size) // Counting Sort
{
    int i, min = array[0], max = array[0];

    for (i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int csize = max - min + 1;

    uint32_t *count = (uint32_t *)malloc((csize + 1) * sizeof(uint32_t));
    uint32_t *arraycopy = (uint32_t *)malloc(size * sizeof(uint32_t));

    if (count == NULL || arraycopy == NULL)
    {
        printf("Error of memory allocation!\n");
        return EXIT_FAILURE;
    }
  
    for (i = 0; i < csize + 1; i++)
    {
        count[i] = 0;
    }
  
    for (i = 0; i < size; i++)
    {
        count[array[i] - min + 1] += 1;
    }

    for (i = 0; i < csize; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        arraycopy[count[array[i] - min]] = array[i];
        count[array[i] - min]++;
    }

    free(count);

    for (int i = 0; i < size; i++)
    {
        array[i] = arraycopy[i];
    }
    
    free(arraycopy);
}

void ISort(uint32_t *array, int size) // Insertion Sort
{
    for (int i = 1; i < size; i++)
    {
        uint32_t temp = array[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[j] < temp)
            break;

            array[j + 1] = array[j];
            array[j] = temp;
        }
    }
}

void QuickSort(uint32_t *array, int left, int right) // Quick Sort
{
    int pivot, tmp;
    int i = left, j = right;
    pivot = array[(i + j) / 2];
    do
    {
        while (array[i]<pivot) i++;
        while (array[j]>pivot) j--;
        if (i<=j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    while (i < j);
    if (left < j) QuickSort(array, left, j);
    if (i < right) QuickSort(array, i, right);
}

