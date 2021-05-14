#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int heap_extract(heap_t **root);
void binary_tree_preorder(heap_t *tree, heap_t **node, size_t h, size_t level);
size_t binary_tree_height(const heap_t *tree);
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
