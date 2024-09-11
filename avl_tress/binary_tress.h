#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic binary tree node structure */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Function prototypes */
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_height(const binary_tree_t *tree);
int is_balanced(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */