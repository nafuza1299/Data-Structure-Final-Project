#ifndef __QUEUE__H
#define __QUEUE__H
//creates the queue throug linked list
template <class type>
//setting the node to point to the next node
struct node
{
	type data;
	node *next;	
};


template <class type>
class Queue
{
		private:
		node<type> *head, *tail;
		int size=0;
		public:
		Queue()
		{
			head=NULL;
			tail=NULL;
		}
    //creates the node
		void createnode(type value)
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
        //pushes new data into the queue
		void push(type value)
		{
			this->size+=1;
			node<type> *temp=new node<type>;
			temp->data=value;
			temp->next=head;
			head=temp;
		}

        //pops and return the data from the queue to a new location
		type pop()
		{	
			this->size-=1;
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
		int qsize() //get the size of the queue
		{
			return this->size;
		}
};


#endif
