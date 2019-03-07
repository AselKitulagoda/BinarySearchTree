
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>



typedef struct tree tree;
typedef struct node node;

node *new_node(int num);

tree *make_tree();

node *insert_node(node *p, int n);

void insert_tree(tree *t, int n);

node *lookup (node *p, int n);

bool wrapcontain (tree *t, int n);

void printTree(node *p);

void reverse(node *p);

int height(node *p);
