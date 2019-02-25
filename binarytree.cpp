#include<stdio.h>
#include<stdlib.h>

struct treenode
{
	int data;
	struct treenode *left;
	struct treenode *right;
} ;
typedef struct treenode Treenode;

//印出二元搜尋樹，inorder traversal
void print_bs_tree(Treenode *root)
{
	if(root==NULL)
	{
		return;
	}
	print_bs_tree(root->left);
	printf("data = %d\n",root->data);
	print_bs_tree(root->right);
}

//插入至二元搜尋樹 
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
		root->left=insert_bs_tree(root->left,data);		//插入至左子樹 
	}
	else
	{
		root->right=insert_bs_tree(root->right,data);	//插入至右子樹 
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
		scanf("%d",&(insert_keys[i]));
	}
	
	Treenode *root=NULL;
	for(i=0;i<5;i++)
	{
		root=insert_bs_tree(root,insert_keys[i]);
	}
	print_bs_tree(root);
	
	system("pause");
	return 0;
}
