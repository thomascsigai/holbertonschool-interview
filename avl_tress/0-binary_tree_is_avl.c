#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value allowed for the current node
 * @max: Maximum value allowed for the current node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (binary_tree_is_bst(tree->left, min, tree->n - 1) &&
            binary_tree_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * is_balanced - Checks if a binary tree is height-balanced
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is balanced, 0 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (1);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (abs(left_height - right_height) > 1)
        return (0);

    return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree));
}
