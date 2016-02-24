#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "NSort.h"
#include "Service.h"

int i, size, mode;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("There's no arguments!\n");
        return EXIT_FAILURE;
    }
    mode = atoi (argv[1]);
    size = 50000;
    FILE * ptr;
    //while (size <= 1000000)
    while (size <= 100000)
    {
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
        switch (mode)
        {
            case 1:
            case 2:
            {
                double t = wtime();
                ISort(array, size);
                t = wtime() - t;
                ptr = fopen("ISort.dat" , "a");
                fprintf (ptr, "%d\t%0.6f\n", size, t);
                fclose(ptr);
                free(array);
                break;
            }
            case 3:
            {
                double t = wtime();
                QuickSort(array, 0, size - 1);
                t = wtime() - t;
                ptr = fopen("QuickSort.dat" , "a");
                fprintf (ptr, "%d\t%0.6f\n", size, t);
                fclose(ptr);
                free(array);
                break;
            }
        }
        size += 50000;
    }
    return EXIT_SUCCESS;
}

