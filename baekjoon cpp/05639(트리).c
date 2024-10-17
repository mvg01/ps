#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	struct TreeNode* left, * right;
	int data;
}TreeNode;

TreeNode* search(TreeNode* root, int key)
{
	if (root == NULL)
		return NULL;
	if (key == root->data)
		return root;
	else if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

TreeNode* newnode(int key)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert(TreeNode* root, int key)
{
	if (root == NULL)
		return newnode(key);

	if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);

	return root;
}

void postorder(TreeNode* root)  //후위순회
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

int main(void)
{
	TreeNode* root = NULL;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		root = insert(root, n);
	}

	postorder(root);
}

