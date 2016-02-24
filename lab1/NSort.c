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
    }
}

void QuickSort(int32_t *array, int left, int right)
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

