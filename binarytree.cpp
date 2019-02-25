#include<stdio.h>
#include<stdlib.h>

struct treenode
{
	int data;
	struct treenode *left;
	struct treenode *right;
} ;
typedef struct treenode Treenode;

//�L�X�G���j�M��Ainorder traversal
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

//���J�ܤG���j�M�� 
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
		root->left=insert_bs_tree(root->left,data);		//���J�ܥ��l�� 
	}
	else
	{
		root->right=insert_bs_tree(root->right,data);	//���J�ܥk�l�� 
	}
	return(root);
}

int main(void)
{
	int i;
	int insert_keys[5];
	
	printf("�п�J5�ӼƦr : "); 
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
