#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/**
 * struct bt_node_queue_s - Binary tree node queue
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next element of the queue
*/
typedef struct bt_node_queue_s
{
    struct binary_tree_s *node;
    struct bt_node_queue_s *next;
} bt_node_queue_t;

int heap_extract(heap_t **root);

#endif /* HEAP_H */