#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: The head of the list
 *
 * Return: Address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head;
    listint_t *fast = head;

    if (head == NULL)
        return (NULL);

    /* Phase 1: Detect if a loop exists */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            /* Phase 2: Find the start of the loop */
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (slow);
        }
    }

    return (NULL);
}
