#ifndef BINARY_H
#define BINARY_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

struct TreeNode
{
	int val;
    int counter;
	TreeNode *lchild;
	TreeNode *rchild;
};	TreeNode *root;

int maxlevel = 0;

void new_node(int value);
void insert(TreeNode *&nodePointer, TreeNode *&newNode);
void print_inorder(TreeNode *nodePointer);
void print_preorder(TreeNode *nodePointer);
void print_postorder(TreeNode *nodePointer);
int count_leafs(TreeNode *nodePointer);
int count_only_child(TreeNode *nodePointer);
TreeNode *search(TreeNode *nodePointer, int value);
bool count_it(TreeNode *nodePointer, int value)
int deepest_level(TreeNode *nodePointer);
TreeNode *deepest(TreeNode *nodePointer, int level, int i);
int count(TreeNode *nodePointer);

#endif