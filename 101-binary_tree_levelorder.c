#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary
 *  tree using level-order traversal
 *
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree,
	void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) *
		binary_tree_size(tree));
	size_t rear = 0;
	size_t front = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		func(node->n);

		if (node->left != NULL)
			queue[rear++] = node->left;
		if (node->right != NULL)
			queue[rear++] = node->right;
	}

	free(queue);
}

