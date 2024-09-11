#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @array: The array where elements are to be swapped
 * @i: The index of the first element
 * @j: The index of the second element
 * @size: The size of the array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
    int temp;

    if (i == j)
        return;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, size);
}

/**
 * heapify - Ensure the subtree rooted at index `i` is a max-heap
 * @array: The array to be heapified
 * @size: The size of the heap
 * @i: The root index of the subtree
 * @heap_size: The size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t heap_size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < heap_size && array[left] > array[largest])
        largest = left;
    if (right < heap_size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(array, i, largest, size);
        heapify(array, size, largest, heap_size);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Build a max-heap */
    for (i = size / 2; i != (size_t)-1; i--)
        heapify(array, size, i, size);

    /* Extract elements one by one */
    for (i = size - 1; i > 0; i--)
    {
        swap(array, 0, i, size);
        heapify(array, size, 0, i);
    }
}
