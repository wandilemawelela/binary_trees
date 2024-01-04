#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 *
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
	{
		return (NULL); /** Return NULL if parent is NULL **/
	}

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL); /** Return NULL on failure **/
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left; /** Set old left-child as left-child **/
	new_node->right = NULL;

	if (parent->left != NULL)
	{
		/** Update the parent pointer of the old left-child **/
		parent->left->parent = new_node;
	}

	parent->left = new_node; /** Set new node as left-child of parent **/
	return (new_node);
}
