#include "binary.h"

using namespace std;

void new_node(int value)
{
	TreeNode *t = nullptr;

	t = new TreeNode;
	t->val = value;
    t->counter = 1;
	t->lchild = nullptr;
	t->rchild = nullptr;

	insert(root, t);
}

void insert(TreeNode *&nodePointer, TreeNode *&newNode)
{
	if (nodePointer == nullptr)
		nodePointer = newNode;
	else if (newNode->val < nodePointer->val)
		insert(nodePointer->lchild, newNode);
	else
		insert(nodePointer->rchild, newNode);
}

void print_inorder(TreeNode *nodePointer)
{
	if (nodePointer)
	{
		print_inorder(nodePointer->lchild);
		outfile << nodePointer->val << "|";
		print_inorder(nodePointer->rchild);
	}
}

void print_preorder(TreeNode *nodePointer)
{
	if (nodePointer)
	{
		outfile << nodePointer->val << "|";
		print_preorder(nodePointer->lchild);
		print_preorder(nodePointer->rchild);
	}
}

void print_postorder(TreeNode *nodePointer)
{
	if (nodePointer)
	{
		print_postorder(nodePointer->lchild);
		print_postorder(nodePointer->rchild);
		outfile << nodePointer->val << "|";
	}
}

int count_leafs(TreeNode *nodePointer)
{
	if (nodePointer == NULL)
	{
		return 0;
	}

	if ((nodePointer->lchild == NULL) && (nodePointer->rchild == NULL))
	{
		return 1;
	}
	else
		return (count_leafs(nodePointer->lchild) + count_leafs(nodePointer->rchild));
}

int count_only_child(TreeNode *nodePointer)
{
	if (nodePointer == NULL)
	{
		return counter;
	}
	else
	{
		if ((nodePointer->lchild == NULL) && (nodePointer->rchild != NULL))
		{
			counter++;
		}
		if ((nodePointer->rchild == NULL) && (nodePointer->lchild != NULL))
		{
			counter++;
		}
		count_only_child(nodePointer->lchild);
		count_only_child(nodePointer->rchild);
	}
	return counter;
}

int count(TreeNode *nodePointer)
{
	if (nodePointer == NULL)
		return 0;
	else
		return nodePointer->counter + count(nodePointer->lchild) + count(nodePointer->rchild);
}

int sum_tree(TreeNode *nodePointer)
{
    if (nodePointer == NULL)
        return 0;
    else
        return (nodePointer->val * nodePointer->counter) + count(nodePointer->lchild) + count(nodePointer->rchild);
}
TreeNode *search(TreeNode *nodePointer, int value)
{
	while (nodePointer)
	{
		if (nodePointer->val == value)
			return nodePointer;
		else if (value < nodePointer->val)
			nodePointer = nodePointer->lchild;
		else
			nodePointer = nodePointer->rchild;
	}
    return NULL;
}

bool count_it(TreeNode *nodePointer, int value)
{
    while (nodePointer)
    {
        if (nodePointer->val == value) {
            nodePointer->counter++;
            return true;
        }
        else if (value < nodePointer->val)
            nodePointer = nodePointer->lchild;
        else
            nodePointer = nodePointer->rchild;
    }
    return false;
}

int deepest_level(TreeNode *nodePointer)
{
	int llevel(0), rlevel(0);
	if (nodePointer == NULL)
	{
		return 0;
	}
	else
	{
		if (nodePointer->lchild)
			llevel = 1 + deepest_level(nodePointer->lchild);
		if (nodePointer->rchild)
			rlevel = 1 + deepest_level(nodePointer->rchild);
		if (llevel < rlevel)
			return rlevel;
		else if (llevel >= rlevel)
			return llevel;
	}
}

TreeNode *deepest(TreeNode *nodePointer, int level, int i)
{
	if (i == level)
		return nodePointer;
	if (nodePointer == NULL)
		return NULL;
	else if (i < level)
	{
		TreeNode *t1 = deepest(nodePointer->rchild, level, i + 1);
		TreeNode *t2 = deepest(nodePointer->lchild, level, i + 1);
		if (!t1 && !t2)
			return NULL;
		else if (!t1)
			return t2;
		else
			return t1;
	}
}