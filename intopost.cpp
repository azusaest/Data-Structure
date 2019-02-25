#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;


struct node
{
	char data;
	struct node *next;
};
typedef struct node Node;

struct stack	
{
	Node *head;
};
typedef struct stack Stack;

Stack stack;
Stack *s=&stack;
		
class topost
{
	public:
		void push(char value);
		char pop();
		int checkop(char data);
		string intopost(char data[20]);
};

void topost::push(char value)
{
	Node *current=(Node*)malloc (sizeof(Node));
	current->data=value;
	current->next=NULL;
	if(s->head==NULL)
	{
		s->head=current;
		return;
	}
	current->next=s->head;
	s->head=current;
}

char topost::pop()
{
	Node *temp;
	char tempdata;
	if(s->head==NULL)
	{
		return '0';
	}
	temp=s->head;
	s->head=s->head->next;
	tempdata=temp->data;
	free(temp);
	return tempdata;
}

int topost::checkop(char data)
{
	switch(data)
	{
		case '*':
		case '/':
			return 3;
			break;
		case '+':
		case '-':
			return 2;
			break;
		case '(':
		case ')':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

string topost::intopost(char data[20])
{
	int i=0,j=0,k=0;
	string result1;
	char result[20]/*={'null'}*/;
	char a;
	do
	{
		if(checkop(data[i])==0)
		{
			result[j]=data[i];
			j++;
		}
		else if(data[i]==')')
		{				
			while(s->head->data!='(')
			{
				a=pop();
				if(a!='0' && a!='(')
				{
					result[j]=a;
					j++;
				}
			}
			pop();
		}
		else if(checkop(data[i])==1 || checkop(data[i])==2 || checkop(data[i])==3)
		{
			if(s->head==NULL || checkop(data[i])>checkop(s->head->data) || data[i]=='(')
			{
				push(data[i]);
			}
			else
			{
				while(s->head!=NULL && s->head->data!='(')
				{
					a=pop();
					if(a!='0')
					{
						result[j]=a;
						j++;
					}
				}
				push(data[i]);
			}
		}
		if(data[i+1]=='\0')
		{	
			while(s->head!=NULL)
			{
				a=pop();
				if(a!='0')
				{
					result[j]=a;
					j++;
				}
			}
		}
		i++;
	}
	while(data[i]!='\0');
	
	result1=result;
	return result1;
} 

int main()
{
	char data[20];
	char a;
	string result2;
	topost b;
	int i=0,j=0,k=0;
	cin>>data;
	result2=b.intopost(data);
	
	cout<<result2;
	
	return 0;
}
