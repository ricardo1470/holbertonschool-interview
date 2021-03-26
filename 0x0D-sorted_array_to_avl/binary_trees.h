#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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

/*Binary Search Tree*/
typedef struct binary_tree_s binary_tree_t;

/*AVL Tree*/
typedef struct binary_tree_s avl_t;

/* Prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *recursive_tree(int *array, int ben, int end);
avl_t *create_node(int n);
void binary_tree_print(const binary_tree_t *tree);

#endif /* SBINARY_TREES_H */
