#include<iostream>
#include<cstdlib>
#include<deque>
#include<Windows.h>
#include<time.h>
#include "Person.h"
#include "Wagon.h"
#include "Station.h "
using namespace std;



int Station::people_amount=1;

void start_day(int rate)
{
	
	double start,end,train_come,train_go,wait;
	string station1name,station2name;//station name
	station1name="Senayan";
	station2name="Blok M";
    //generates the timer
	start=GetTickCount();
	end=start+24000; //24000 milliseconds = 24 seconds, with each second representing one hour in real life time
	train_come=GetTickCount();
	int NoOfTrip;
	wait=500;
	
	
	//creates the object station1 and station 2
	Station station1(station1name);
	Station station2(station2name);
	station1.set_next(&station2);
	station2.set_next(&station1);

	Wagon Train1(100,&station1);
	
	
    // loops for 24 seconds before termination
	while(GetTickCount()<end)
		{
			Sleep(5);
			
			station1.generate_people(rate);
			station2.generate_people(rate);
			
			if(GetTickCount()-train_come>=wait&&!Train1.door_open)
			{
				/*this if is used for opening train's door*/
				Train1.come();
				Train1.opendoor();
		
				train_go=GetTickCount();//set train counter to current time
				
			}
			
			if(GetTickCount()-train_go>=wait&&Train1.door_open)
			{
				/*this if used for closing train's door*/
				Train1.closedoor();
				Train1.departure();
				train_come=GetTickCount();//set train counter to current time
				NoOfTrip+=1;
			}
			if(Train1.curr->get_name()==station1name) //Train has arrived at station1
			{
			
				if(station1.people.qsize()>0&&Train1.door_open) // if size is available train door is open
				{	
					for (int x=0;x<station1.people.qsize();x++)
					{
						if(Train1.isnotfull())
						{
							Train1.peoplein(station1.people.pop()); //pops and return people from station 1 into array
						}
					}
				}
			}
			if(Train1.curr->get_name()==station2name) //Train has arrived at station2
			{
			
				if(station1.people.qsize()>0&&Train1.door_open) // if size is available train door is open
				{	
					for (int x=0;x<station2.people.qsize();x++)
					{
						if(Train1.isnotfull())
						{
							Train1.peoplein(station2.people.pop()); //pops and return people from station 2 into array
						}
					}
				}
			}

		}
	
		cout<<"Number of passengers that arrived at Senayan station: "<<station1.arrived.qsize()<<endl;
		cout<<"Number of passengers that arrived at Blok Mstation: "<<station2.arrived.qsize()<<endl;
		cout<<"Number of train trips: "<<NoOfTrip<<endl;
		cout<<"Passegners who did not get a seat:"<<station1.people.qsize()+station2.people.qsize()<<endl;
		cout<<"Senayan Station("<<station1.people.qsize()<<")"<<endl;
		cout<<"Senayan Station("<<station2.people.qsize()<<")"<<endl;
		cout<<"Simulation has finished"<<endl;
}


int main()
{		
	int input;
	while (true)
	{
	cout<<"Select the day you want to simulate"<<endl;
	cout<<"1.Work Days"<<endl;
	cout<<"2.Holidays"<<endl;
	cout<<"3.Exit"<<endl;
	cin>>input;
	
	switch (input)
		{
		case 1:	
			start_day(8); //sets the range of random from 100 to 8
			break;
		case 2:
			start_day(4);//sets the range of random from 100 to 4
			break;	
		
		default:
			return 0;		
		}
		//Sleep(10000);
		//system("CLS");
	}
	return 0;
}
