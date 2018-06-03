#ifndef __WAGON_H
#define __WAGON_H

#include "Seat.h"
#include "Station.h"
using namespace std;

class Wagon
{
	//capacity of seat
	int id;
	public:
		Seat Capacity[100];
		bool door_open = false;
		Station *curr;//current station
		
		Wagon(int idnumber,Station *starting)//this is the constructor
		{				
			this->curr = starting;
			this->id=idnumber;
			cout << "Train has been build, Train ID =" << this->id << endl;
			
			for (int x=0;x<100;x++)
			{
				this->Capacity[x] = Seat(x+1);//seat is constructed when the train constructed
			}
		}
		
		void opendoor() //specifies that the state of the door is true
		{
			cout<<"Door is opened"<<endl;
			this->door_open=true;
		}
		
		void closedoor() //specifies that the state of the door is false
		{
			cout<<"Door is closed"<<endl;
			this->door_open=false;
		}

		void come()  //Arrival of the train and unloading the passengers
		{	
			
			for (int x=0;x<100;x++)
			{
				if(!Capacity[x].avail)
				{
					this->curr->arrived.push(Capacity[x].get_person());
                    cout<<"Passengers with ticket #"<<Capacity[x].people.get_ticketno()<<" have arrived at: "<<curr->get_name()<<endl;
					Capacity[x].set_free(); //clears the array
				}
			}
			cout<<"MRT arrived at:"<<this->curr->get_name()<<endl;
		
		}
		
		void departure() //if capacity of the train is available
		{
			Station *temp;
			temp=this->curr;
			this->curr=this->curr->next;
			this->curr->next=temp;
			
			cout<<"Train has departed"<<endl;

		}
		
		bool isnotfull()//checks if the capacity has been met or not
		{
			for (int x=0;x<100;x++)
			{
				if (this->Capacity[x].avail)//avail
				{
					//cout<<"There is Free spot"<<endl;
					return true;
				}	
			}
			//cout<<"No space left"<<endl;
			return false;	
		}
		
		

		
		void peoplein(Person in) //inserts the passengers into the train
		{
			if(this->isnotfull())//if train is not full 
			{
				for (int x = 0;x < 100; x++)
				{	/*loop for inserting ppl into their seat*/
					if(Capacity[x].avail)
					{
						Capacity[x].set_occupied();
						Capacity[x].set_people(in);
                        cout<<"Passenger with ticket #"<<in.get_ticketno()<<" is in seated in seat #"<<Capacity[x].get_number()<<endl;
						break;			
					}
				}				
			}
		}
		
		string get_location()
		{
			return this->curr->get_name();
		}
};


#endif
