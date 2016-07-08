#include<stdio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//start function
struct node *to_doubly(struct node *root);

//main logic(LEFT-RIGHT-MERGE)
struct node * binary_tree_to_doubly_LL(struct node *root, int direction);

//connect a node to child nodes
void merge(struct node *root);

/*
Making a node with two childs as doubly LL.
*/
void connect(struct node *root)
{
	if (root->left != NULL)
		root->left->right = root;
	if (root->right != NULL)
		root->right->left = root;
}

//Going in the order of postfix notation(LEFT-RIGHT-VISIT) and connecting the nodes.
//direction tells whether the last call is going left(1) or right(2) 
struct node * binary_tree_to_doubly_LL(struct node *root, int direction)
{
	if (root == NULL)
	{
		return NULL;
	}
	//connecting left sub tree of a node
	root->left = binary_tree_to_doubly_LL(root->left, 1);
	
	//connecting right sub tree of a node
	root->right = binary_tree_to_doubly_LL(root->right, 2);
	
	//connect the node with left connected subtree and right connected sub tree
	connect(root);
	
	//if last call is left we have to return the right most connected node
	if (direction == 1 && root->right != NULL)
	{
		while (root->right != NULL)
		{
			root = root->right;
		}
	}
	
	//if last call is right we have to return the left most connected node
	else if (direction == 2 && root->left != NULL)
	{
		while (root->left != NULL)
		{
			root = root->left;
		}
	}
	
	return root;
}

struct node *to_doubly(struct node *root)
{
  //to get the left most connected node we are sending the direction as right
	root = binary_tree_to_doubly_LL(root, 2);
	return root;
}
