#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a node to the end of a double circular linked list.
 * @list: Double pointer to the head of the list.
 * @str: The string to copy into the new node.
 * 
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
    List *new_node;
    List *temp;

    if (str == NULL)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    if (*list == NULL)
    {
        /* The list is empty */
        new_node->next = new_node;
        new_node->prev = new_node;
        *list = new_node;
    }
    else
    {
        /* The list is not empty */
        temp = (*list)->prev;

        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = *list;
        (*list)->prev = new_node;
    }

    return (new_node);
}

/**
 * add_node_begin - Adds a node to the beginning of a double circular linked list.
 * @list: Double pointer to the head of the list.
 * @str: The string to copy into the new node.
 * 
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node;
    List *temp;

    if (str == NULL)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    if (*list == NULL)
    {
        /* The list is empty */
        new_node->next = new_node;
        new_node->prev = new_node;
        *list = new_node;
    }
    else
    {
        /* The list is not empty */
        temp = (*list)->prev;

        new_node->next = *list;
        new_node->prev = temp;
        (*list)->prev = new_node;
        temp->next = new_node;
        *list = new_node;
    }

    return (new_node);
}
