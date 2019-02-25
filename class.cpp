#include <iostream>
using namespace std;

 class Dnode
 {
 	public:
 		Dnode()
 		{
 			next=NULL;
 			prev=NULL;
 		};
 		int data;
 		void setnext(Dnode *s)
 		{
 			this->next=s;
 		};
 		void setpre(Dnode *s)
 		{
 			this->prev=s;
 		};
 		Dnode *getnext()
		{ 
	        return next;
		};
		Dnode *getpre()
		{ 
	        return prev;
		};
 	private:
 		Dnode *next;
 		Dnode *prev;
 };
 
 struct doublelist
 {
 	Dnode *head=NULL;
 	Dnode *tail=NULL;
 };
 typedef struct doublelist Double;
 Double doublelist;
 Double *s=&doublelist;
 
 void insert_front(int value)
 {
 	Dnode *current=new Dnode;
 	current->data=value;
 	if(s->head==NULL)
 	{
 		s->head=current;
 		s->tail=s->head;
 		return;
 	}
 	else
 	{
 		s->head->setpre(current);
 		current->setnext(s->head);
 		s->head=current;
 		return;
 	}
 }
 
 void insert_back(int value)
 {
 	Dnode *current=new Dnode;
 	current->data=value;
 	if(s->tail==NULL)
 	{
 		s->tail=current;
 		s->head=s->tail;
 		return;
 	}
 	else
 	{
 		s->tail->setnext(current);
 		current->setpre(s->tail);
 		s->tail=current;
 		return;
 	}
 }
 
 int main()
 {
 	Dnode *current;
 	int a,b,i=0;
 	while(1)
 	{
 		cout << "請輸入插入linked list的位置(0表示頭，1表示尾) : " ;
 		cin>>a;
 		if(a==0)
 		{
		 	cout << "請輸入插入的數字 : " ;
 			cin>>b;
 			insert_front(b);
 		}
 		else if(a==1) 
 		{
 			cout << "請輸入插入的數字 : " ;
 			cin>>b;
 			insert_back(b);
 		}
		else
 		{
 			continue;
 		}
 		current=s->head;
 		for(;;)
		{
			cout<<"->";
			cout<<current->data;
			if(current==s->tail)
			{
				break;
			}
			current=current->getnext();
		}
		cout<<"\n";
 	}
 	return 0;
 }
