#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: integer
 * @number: points to the next node
 *
 * return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
    listint_t *current;
    
    if (new_node == NULL) {
        return NULL;
    }

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || number < (*head)->n) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }
    
    current = *head;

    while (current->next != NULL && current->next->n < number) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}