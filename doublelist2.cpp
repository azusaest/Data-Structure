#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Dinfo
{
	public:
		Dinfo()
		{
			head=NULL;
			tail=NULL;
			sorthead=NULL;
			sorttail=NULL;
		};
		Dinfo(int _number,string _name,bool _sex,string _mail)
		{
			number=_number;
			name=_name;
			sex=_sex;
			mail=_mail;
		};
		int number;
		string name;
		bool sex;
		string mail;
		void setnext(Dinfo *ptr)
		{
			Dinfo *current=ptr;
			current->next=NULL;
			current->prev=NULL;
			if(head==NULL)
			{
				head=current;
				tail=head;
				return;
			}
			tail->next=current;
			current->prev=tail;
			tail=current;
		};
		void setpre(Dinfo *ptr)
		{
			Dinfo *current=ptr;
			current->next=NULL;
			current->prev=NULL;
			if(tail==NULL)
			{
				tail=current;
				head=tail;
				return;
			}
			head->prev=current;
			current->next=head;
			head=current;
		};
		void number_sort(Dinfo *ptr)
		{
			Dinfo *current=ptr;
			Dinfo *ptr1=sorthead;
			current->next=NULL;
			current->prev=NULL;
			if(sorthead==NULL)
			{
				sorthead=current;
				sorttail=sorthead;
				return;
			}
			while(ptr1->getnext()!=NULL && ptr1->number<current->number)
			{
				ptr1=ptr1->getnext();
			}
			if(ptr1->getnext()==NULL && ptr1->number<current->number)
			{
				ptr1->next=current;
				current->prev=ptr1;
				return;
			}
			else
			{
				current->next=ptr1;
				current->prev=ptr1->prev;
				ptr1->prev=current;
				current->prev->next=current;
				return;
			}
		};
		/*void delete_info(Dinfo *ptr)
		{
			
		}*/
		Dinfo *getnext(){return next;}; 
		Dinfo *getpre(){return prev;};
		Dinfo *gethead(){return head;};
		Dinfo *gettail(){return tail;};
		Dinfo *getsorthead(){return sorthead;};
		Dinfo *getsorttail(){return sorttail;};
	private:
		Dinfo *next;
		Dinfo *prev;
		Dinfo *head;
		Dinfo *tail;
		Dinfo *sorthead;
		Dinfo *sorttail;
};


int main()
{
	Dinfo a;
	Dinfo *ptr=new Dinfo(1,"abc",1,"abc");
	//a.setnext(ptr);
	a.number_sort(ptr);
	Dinfo *ptr1=new Dinfo(2,"def",2,"def");
	//a.setnext(ptr1);
	a.number_sort(ptr1);
	Dinfo *ptr2=new Dinfo(4,"ghi",4,"ghi");
	//a.setnext(ptr2);
	a.number_sort(ptr2);
	Dinfo *ptr3=new Dinfo(3,"jkl",3,"jkl");
	//a.setnext(ptr3);
	a.number_sort(ptr3);
	Dinfo *current;
	current=a.getsorthead();
	while(current!=NULL)
	{
		cout<<current->name<<endl;
		current=current->getnext();
	}
	return 0;
}
