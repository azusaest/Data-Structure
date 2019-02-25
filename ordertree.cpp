#include<stdio.h>
#include<stdlib.h>

struct treenode
{
	int data;
	struct treenode *left;
	struct treenode *right;
} ;
typedef struct treenode Treenode;

void inorder_bs_tree(Treenode *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder_bs_tree(root->left);
	printf("data = %d\n",root->data);
	inorder_bs_tree(root->right);
	return;
}

void preorder_bs_tree(Treenode *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("data = %d\n",root->data);
	preorder_bs_tree(root->left);
	preorder_bs_tree(root->right);
	return;
}

void postorder_bs_tree(Treenode *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder_bs_tree(root->left);
	postorder_bs_tree(root->right);
	printf("data = %d\n",root->data);
	return;
}

Treenode *insert_bs_tree(Treenode *root,int data)
{
	struct treenode *current;
	if(root==NULL)
	{
		current=(Treenode *)malloc(sizeof(Treenode));
		current->data=data;
		current->left=NULL;
		current->right=NULL;
		return(current);
	}
	if(data<root->data)
	{
		root->left=insert_bs_tree(root->left,data);
	}
	else
	{
		root->right=insert_bs_tree(root->right,data);
	}
	return(root);
}

int main(void)
{
	int i;
	int insert_keys[5];
	
	printf("請輸入5個數字 : ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&insert_keys[i]);
	}
	Treenode *root=NULL;
	for(i=0;i<5;i++)
	{
		root=insert_bs_tree(root,insert_keys[i]);
	}
	printf("inorder\n");
	inorder_bs_tree(root);
	printf("preorder\n");
	preorder_bs_tree(root);
	printf("postorder\n");
	postorder_bs_tree(root);
	
	system("pause");
	return 0;
}
