/***¹ê§@doubly linked list***/ 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev;
	struct node *next;
} ;
typedef struct node Node;

Node *head=NULL;
Node *tail=NULL;

//insert front
void insert_double_list(int value)
{
	Node *current=(Node*)malloc(sizeof(Node));
	current->data=value;
	current->prev=NULL;
	current->next=NULL;
	if(head==NULL)
	{
		head=current;
		tail=head;
		return;
	}
	tail->next=current;
	current->prev=tail;
	tail=current;
}

//insert back
void insert_back_double_list(int value)
{
	Node *current=(Node*)malloc(sizeof(Node));
	current->data=value;
	current->prev=NULL;
	current->next=NULL;
	if(tail==NULL)
	{
		tail=current;
		head=tail;
		return;
	}
	head->prev=current;
	current->next=head;
	head=current;
}

//delete number
void delete_double_list(int value)
{
	Node *temp;
	temp=head;
	
	if(temp==NULL)
	{
		cout<<"No Number!\n";
		return;
	}
	while(temp->data!=value)
	{
		if(temp==tail && temp->data!=value)
		{
			break;
		}
		temp=temp->next;
	}
	
	if(temp==tail && temp->data!=value)
	{
		cout<<"Not Found!\n";
		return;
	}
	else if(head==tail)
	{
		temp->next=NULL;
		temp->prev=NULL;
		head=NULL;
		tail=NULL;
		free(temp);
		return;
	}
	else if(temp==head)
	{
		head=temp->next;
		temp->next->prev=NULL;
		temp->next=NULL;
		free(temp);
		return;
	}
	else if(temp==tail)
	{
		tail=temp->prev;
		temp->prev->next=NULL;
		temp->prev=NULL;
		free(temp);
		return;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	temp->next=NULL;
	temp->prev=NULL;
	free(temp);
}

int main()
{
	int input1,input2,input3;
	Node *current=(Node*)malloc(sizeof(Node));
	while(1)
	{
		cout<<"(1)insert(2)insert back(3)delete(4)break:";
		cin>>input1;
		if(input1==1)
		{
			cout<<"\ninsert number:";
			cin>>input2;
			insert_double_list(input2);
			cout<<"head";
			for(current=head;current!=NULL;current=current->next)
			{
				cout<<"->";
				cout<<current->data;
			}
			cout<<"->tail"<<endl;
			
			cout<<"tail";
			for(current=tail;current!=NULL;current=current->prev)
			{
				cout<<"->";
				cout<<current->data;
			}
			cout<<"->head\n\n";
		}
		else if(input1==2)
		{
			cout<<"\ninsert number:";
			cin>>input2;
			insert_back_double_list(input2);
			cout<<"head";
			for(current=head;current!=NULL;current=current->next)
			{
				cout<<"->";
				cout<<current->data;
			}
			cout<<"->tail"<<endl;
			
			cout<<"tail";
			for(current=tail;current!=NULL;current=current->prev)
			{
				cout<<"->";
				cout<<current->data;
			}
			cout<<"->head\n\n";
		}
		else if(input1==3)
		{
			cout<<"\ndelete number:";
			cin>>input3;
			delete_double_list(input3);
			cout<<"head";
			for(current=head;current!=NULL;current=current->next)
			{
				cout<<"->";
				cout<<current->data;
			}
			cout<<"->tail"<<endl;
			
			cout<<"tail";
			for(current=tail;current!=NULL;current=current->prev)
			{
				cout<<"->";
				cout<<current->data;
			}
			cout<<"->head\n\n";
		}
		else if(input1==4)
		{
			break;
		}
	}
	system("pause");
	return 0;
}
