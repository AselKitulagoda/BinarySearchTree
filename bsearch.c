#include "bsearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

//structure of Node
struct node
{   struct node *left;
    int val;
    struct node *right;
};
//Making a tree struture
struct tree {
struct node *root;
};

//making a new node
node *new_node(int num){
  node *p = malloc(sizeof(node));
  p->left = NULL;
  p->val = num;
  p->right = NULL;
  return p;
}

//making a tree structure
tree *make_tree(){
tree *t = malloc(sizeof(tree));
t->root = NULL;
return t;
}

//inserting a new_node
node *insert_node(node *p, int n){
    if (p==NULL) p = new_node(n);
    if (n < p->val)
      p->left = insert_node(p->left,n);
    else if (n > p->val)
      p->right = insert_node(p->right,n);
    return p;
}
//inserting a new_node into a tree
void insert_tree(tree *t, int n){
  t->root = insert_node(t->root,n);
}
//lookup whether a number is in a tree
node *lookup (node *p, int n){
  if (p == NULL);
  if (n < p->val) (p= lookup(p->left, n));
  else if (n > p->val) (p=lookup(p->right,n));
  return p;
}
//allows the lookup function to be applied to trees
bool wrapcontain (tree *t, int n){
 return lookup(t->root,n) != NULL;
}
//prints all nodes in a tree
void printTree(node *p){
if (p==NULL) return;
printTree(p->left);
printf("%d\n", p->val);
printTree(p->right);
}
//moves all the nodes in the right of the tree to the left
void reverse(node *p){
if (p == NULL)
  return;
else {
node *temp;
reverse(p->left);
reverse(p->right);
temp = p->left;
p->left = p->right;
p->right = temp;
}
}
//finds the maximum height of a tree
int height(node *p){
if (p == NULL)
  return(0);
else {
int lefth = height(p->left);
int righth = height(p->right);
if (lefth > righth) return (lefth+1);
else return (righth+1);
}
}

//-----------------------------------------Testing------------------------------
//testing making a new node
void testNewNode(){
node *l = new_node(4);
assert(l->left == NULL);
assert(l->right == NULL);
assert(l->val == 4);
printTree(l);
node *g = new_node(10);
assert(g->left == NULL);
assert(g->right == NULL);
assert(g->val == 10);
printTree(g);
}
//testing insert node
void testInsert(){
  node *l = new_node(50);
  insert_node(l, 49);
  insert_node(l, 51);
  printTree(l);
  assert(l->val == 50);
  assert(l->left->val == 49);
  assert(l->right->val == 51);
}
//testing look up function using Wrapper
void testlookup(){
  tree *t = make_tree();
  insert_tree(t, 50);
  insert_tree(t, 49);
  insert_tree(t, 51);
  assert(wrapcontain(t, 49) == true);
}
//testing the reverse function
void testReverse(){
node *l = new_node(50);
insert_node(l,49);
insert_node(l,51);
reverse(l);
assert(l->val == 50);
assert(l->right->val == 49);
assert(l->left->val == 51);

}
//testing max height of a tree
void testheight(){
node *l = new_node(50);
insert_node(l,49);
insert_node(l,51);
assert(height(l) == 2);
}

//main function
int main(){
  testInsert();
  testNewNode();
  testlookup();
  testReverse();
  testheight();
  printf("all tests passed\n");
}
