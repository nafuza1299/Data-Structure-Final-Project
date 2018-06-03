#ifndef __STATION_H
#define __STATION_H


#include "Queue.h"

using namespace std;
//creates the MRT station, specifying it's name and can generate the passenger

class Station
{
	string Station_name; 
	public:
		int static people_amount;
		Station *next;
		Queue<Person> people;
		Queue<Person> arrived;
		 
		Station(string name) //constructor for class station
		{
			this->Station_name = name;
			cout<< "STATION " << this->Station_name << " IS CREATED" <<endl;
		}
    
		void generate_people(int rate) //generates passenger and the total amount is randomly generated
		{	
			srand(time(NULL));
			int ranum=rand() % 10 + 1;
			if (ranum<=rate)
			{
				people.push(Person(this->people_amount));//passengers are created and pushed into queue
				this->people_amount++;
				cout<<this->Station_name<<endl;
			}	
		}
		void set_next(Station *next) //links the two stations together
		{
			this->next=next;
		}
		string get_name()
		{
			return this->Station_name;
		}
		Station(){}
};

#endif
