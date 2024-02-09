#include "lists.h"
#include <stdlib.h>

int is_palindrome(listint_t **head)
{
    listint_t *fast = *head, *slow = *head;
    listint_t *stack = NULL, *temp;
    int stackSize = 0;

    if (!*head) {
        return 1;
    }

    while (fast && fast->next) {
        temp = (listint_t *)malloc(sizeof(listint_t));

        if (!temp)
            return (0);
        
        temp->n = slow->n;
        temp->next = stack;
        stack = temp;
        stackSize++;

        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) {
        slow = slow->next;
    }

    while (slow) {
        if (stack->n != slow->n) 
        {
            while (stack)
            {
                temp = stack;
                stack = stack->next;
                free(temp);
            }
            return (0);
        }
        slow = slow->next;
        temp = stack;
        stack = stack->next;
        free(temp);
        stackSize--;
    }

    return 1;
}