#include<iostream>
using namespace std;

template <class type>

struct node
{
	type data;
	node *right;
	node *left;
	
};


template <class type>
class list
{
		private:
		node<type> *head, *tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(type value)
		{
			node<type> *temp=new node<type>;
			temp->data=value;			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node<type> *temp=new node<type>;
			temp=head;
			if (temp!=NULL)
				while(temp!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
			else
				cout<<"stack/queue is empty"<<endl;
		}
		void insert_start(type value)
		{
			node<type> *temp=new node<type>;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insert_position(int pos, type value)
		{
			node<type> *pre=new node<type>;
			node<type> *cur=new node<type>;
			node<type> *temp=new node<type>;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=value;
			pre->next=temp;	
			temp->next=cur;
		}
		void delete_first()
		{
			node<type> *temp=new node<type>;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last()
		{
			node<type> *current=new node<type>;
			node<type> *previous=new node<type>;
			current=head;
			while(current->next!=NULL)
			{
				previous=current;
				current=current->next;	
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos)
		{
			node<type> *current=new node<type>;
			node<type> *previous=new node<type>;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
		type pop()
		{	
			type popnum;
			node<type> *current=new node<type>;
			node<type> *previous=new node<type>;
			current=head;
			if (current->next==NULL)
			{
				popnum=current->data;
				head=NULL;
				delete head;
				return popnum;
			}
			else
			{
			
				while(current->next!=NULL)
				{
					previous=current;
					current=current->next;	
				}
				tail=previous;
				previous->next=NULL;
				popnum=current->data;
				delete current;
				return popnum;
			}
		}
		void Enqueue(type value)
		{
			node<type> *temp=new node<type>;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void Dequeue()
		{
			node<type> *temp=new node<type>;
			if (head!=NULL)
				temp=head;
				head=head->next;
				delete temp;
		}
};

