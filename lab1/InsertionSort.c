#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int i, j, temp, size;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("There's no arguments!\n");
        return EXIT_FAILURE;
    }
    size = atoi (argv[1])-1;
    int32_t *array = (int32_t*) malloc(size * sizeof(int32_t));
    if (array == NULL)
    {
        printf("Error of memory allocation!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < size; i++)
    {
        array[i] = getrand(1, 100);
        printf("%d ", array[i]);
    }
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        for (j = i - 1; j >= 0; j--)
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
    free(array);
    return EXIT_SUCCESS;
}

