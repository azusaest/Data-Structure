#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*class Node
{
	public:
		Node()
		{
			
		};
		char data;
		void PreOrder(Node ptr){};
		void PostOrder(Node ptr){};
	private:
		Node *left_child;
		Node *right_child;
};*/
struct node
{
	char data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

struct node1
{
	Node *root;
	struct node1 *next;
};
typedef struct node1 Node1;

struct stack
{
	Node1 *head;
};
typedef struct stack Stack;

Stack stack;
Stack *s=&stack;

void push(char value)
{
	Node1 *current=(Node1*)malloc(sizeof(Node1));
	current->root->data=value;
	current->next=NULL;
	if(s->head==NULL)
	{
		s->head=current;
		return;
	}
	if(value=='+')
	{
		current->root->left=s->head->next->root;
		current->root->right=s->head->root;
		return;
	}
	current->next=s->head;
	s->head=current;
	
}

/*Node::PreOrder(Node ptr)
{
	if(ptr!=NULL)
	{
		printf("%c",ptr->data);
		PreOrder(ptr->left_child);
		PreOrder(ptr->right_child);
	}
}

void inorder(Node1 ptr)
{
	if(ptr->data=='(')
	{
		inorder(ptr->next);
	}
	else if()
}

Node::PostOrder(Node ptr)
{
	if(ptr!=NULL)
	{
		PostOrder(ptr->left_child);
		PostOrder(ptr->right_child);
		printf("%c",ptr->data);
	}
}*/

int main()
{
	char a;
	while(1)
	{
		cin>>a;
		push(a);
		cout<<s->head->root->data;
	}
	return 0;
} 
