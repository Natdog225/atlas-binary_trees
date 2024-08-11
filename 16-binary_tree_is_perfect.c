#include "binary_trees.h"

/**
 * _is_perfect_recursive - Helper function to check if a subtree is perfect
 * @tree: Pointer to the root of the subtree
 * @depth: Depth of the node in the main tree
 * @level: Current level being checked (starts from 0 at the root)
 *
 * Return: 1 if the subtree is perfect, 0 otherwise
 */
static int _is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (0);

	/* If it's a leaf node, check if it's at the expected depth for a perfect tree */
	if (tree->left == NULL && tree->right == NULL)
		return (level == depth ? 1 : 0);

	/* Check if both children exist and are perfect at the next level */
	if (tree->left != NULL && tree->right != NULL)
		return (_is_perfect_recursive(tree->left, depth, level + 1) &&
				_is_perfect_recursive(tree->right, depth, level + 1));

	return (0); /* If one child is NULL and the other isn't, or if children aren't perfect, it's not perfect */
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise. 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	return (_is_perfect_recursive(tree, height, 0));
}
