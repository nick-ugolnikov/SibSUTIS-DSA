#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "NSort.h"
#include "Service.h"

int i, size;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("There's no arguments!\n");
        return EXIT_FAILURE;
    }
    size = atoi (argv[1]);
    int32_t *array = (int32_t*) malloc(size * sizeof(int32_t));
    if (array == NULL)
    {
        printf("Error of memory allocation!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = getrand(1, 100000);
    }
    
    double t1 = wtime();
    ISort(array, size);
    t1 = wtime() - t1;

    for (int i = 0; i < size; i++)
    {
        array[i] = getrand(1, 100000);
    }

    double t2 = wtime();
    QuickSort(array, 0, size - 1);
    t2 = wtime() - t2;

    printf("Executable time InsertionSort: %f seconds.\n", t1);
    printf("Executable time QuickSort: %f seconds.\n", t2);
    free(array);
    return EXIT_SUCCESS;
}

