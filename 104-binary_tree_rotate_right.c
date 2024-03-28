#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 *
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Pointer to the new root node after rotation, or NULL if tree is NULL
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tree->left = pivot->right;

	if (pivot->right != NULL)
		pivot->right->parent = tree;

	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (pivot);
}
