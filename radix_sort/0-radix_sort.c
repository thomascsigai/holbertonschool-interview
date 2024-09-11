#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - A function to perform counting sort based on a specific digit.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 * @exp: The digit position to sort on (1 for units, 10 for tens, etc.)
 */
static void counting_sort(int *array, size_t size, int exp)
{
    int *output, count[10] = {0};
    size_t i;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    /* Count occurrences of each digit */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Update count[i] to contain actual position of this digit in output[] */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / exp) % 10]--;
    }

    /* Copy the output array to array[] */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free the memory allocated for output */
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to figure out the number of digits */
    max = array[0];
    for (size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Perform counting sort for each digit */
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}
