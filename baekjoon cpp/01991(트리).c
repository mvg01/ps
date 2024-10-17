#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	struct TreeNode* left, * right;
	char data;
}TreeNode;

void inorder(TreeNode* node)
{
	if (node != NULL) {
		inorder(node->left);
		printf("%c", node->data);
		inorder(node->right);
	}
	
}
void preorder(TreeNode* node)
{
	if (node != NULL) {
		printf("%c", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(TreeNode* node)
{
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf("%c", node->data);
	}
}

TreeNode* search(TreeNode* node, char key)
{
	if (node != NULL) {
		if (node->data == key) {
			return node;
		}
		else {
			TreeNode* find = search(node->left, key);
			if (find != NULL)
				return find;
			else
				return search(node->right, key);
		}
	}
	return NULL;
}

TreeNode* newnode(char ch)
{
	TreeNode* pnode = (TreeNode*)malloc(sizeof(TreeNode));
	pnode->data = ch;
	pnode->left = NULL;
	pnode->right = NULL;
	return pnode;
}

void insert_node(TreeNode* root, char node, char left, char right)
{
	root->data = node;
	if (left != '.')
		root->left = newnode(left);
	if (right != '.')
		root->right = newnode(right);
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	TreeNode* root = newnode(NULL); //비어있는 루트노드
	TreeNode* tree;

	for (int i = 0; i < n; i++)
	{
		char data, left, right;
		scanf(" %c %c %c", &data, &left, &right);

		tree = search(root, data);
		if (tree == NULL) {   //비어있는 (처음) 노드이면
			insert_node(root, data, left, right);
		}
		else {
			insert_node(tree, data, left, right);
		}
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}