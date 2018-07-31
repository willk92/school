#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

ofstream outfile;
ifstream infile;

struct TreeNode
{
	int val;
	int counter;
	TreeNode *lchild;
	TreeNode *rchild;
};	TreeNode *root;

int counter = 0;
int maxlevel = 0;

void new_node(int value);
void insert(TreeNode *&nodePointer, TreeNode *&newNode);
void print_inorder(TreeNode *nodePointer);
void print_preorder(TreeNode *nodePointer);
void print_postorder(TreeNode *nodePointer);
int count_leafs(TreeNode *nodePointer);
int count_only_child(TreeNode *nodePointer);
TreeNode *search(TreeNode *nodePointer, int value);
int deepest_level(TreeNode *nodePointer);
TreeNode *deepest(TreeNode *nodePointer, int level, int i);
int count(TreeNode *nodePointer);
int count_duplicate(TreeNode *nodePointer);
int sum_of_tree(TreeNode *nodePointer, int sum);

int main()
{
	infile.open("TreeNbrsV2.txt");
	outfile.open("tree_results.txt");
	outfile << "tree_results.txt\nWilliam Kelley\nCS372\n\n\n";
	int x;
	int sum = 0;
	while (infile >> x)
	{
		TreeNode *temp;
		temp = search(root, x);
		if (temp)
			temp->counter++;
		else
			new_node(x);
	}
	outfile << endl;
	infile.close();
	outfile << "a)  In-Order Traversal:\n";
	print_inorder(root);
	outfile << endl;
	outfile << "b)  Pre-Order Traversal:\n";
	print_preorder(root);
	outfile << endl;
	outfile << "c)  Post-Order Traversal:\n";
	print_postorder(root);
	outfile << endl;
	outfile << "d)  Number of Nodes: " << count(root) << endl;
	outfile << "e)  Sum of Tree: " << sum_of_tree(root, 0) << endl;
	outfile << "    Average Tree Value: " << (sum_of_tree(root, 0) / count(root)) << endl;
	outfile << "f)  Number of Duplicates: " << count_duplicate(root) << endl;
	outfile << "g)  Number of Leaves: " << count_leafs(root) << endl;
	outfile << "h)  Single Child Nodes: " << count_only_child(root) << endl;
	outfile << "i)  Deepest Node Value: " << (deepest(root, deepest_level(root), 0)->val) << endl;
	outfile << "j)  Number of Nodes(Left Subtree): " << count(root->lchild) << endl;
	outfile << "    Number of Nodes(Right Subtree): " << count(root->rchild) << endl;
	
	outfile.close();
}

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

int count_duplicate(TreeNode *nodePointer)
{
	if (nodePointer == NULL)
		return 0;
	else
	{
		if (nodePointer->counter > 1)
			return 1 + count_duplicate(nodePointer->lchild) + count_duplicate(nodePointer->rchild);
		else
			return 0 + count_duplicate(nodePointer->lchild) + count_duplicate(nodePointer->rchild);
	}
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

int sum_of_tree(TreeNode *nodePointer, int sum)
{
	if (!nodePointer)
		return 0;
	else
		return (nodePointer->counter * nodePointer->val) + sum_of_tree(nodePointer->lchild, sum) + sum_of_tree(nodePointer->rchild, sum);
}