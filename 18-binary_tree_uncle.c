#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL
 * or there is no uncle. Sad.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL); /* No uncle if node, its parent, or grandparent is NULL */

	/* Find the sibling of the node's parent */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right); /* Parent is left child, uncle is right child */
	else
		return (node->parent->parent->left); /* Parent is right child, uncle is left child */
}
