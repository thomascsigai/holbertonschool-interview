#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *fastPointer;
    listint_t *slowPointer;

    if (!list)
        return (0);
    
    fastPointer = list;
    slowPointer = list;

    do
    {
        if (!slowPointer->next || !fastPointer->next || !fastPointer->next->next)
            return (0);

        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    } while (fastPointer != slowPointer);

    return (1);
}