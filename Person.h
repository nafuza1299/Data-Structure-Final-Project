#ifndef __PERSON_H
#define __PERSON_H

//generates distinct ticket for each passenger
using namespace std;

class Person
{
	int tiketnumb;
	public:
		
			Person (){}
			Person(int no) //int no is the parameter for the generated ticket number
			{	
				this->tiketnumb=no;
                cout << "Passenger tapped ticket "<< this-> tiketnumb <<" at station: ";	//displays that passengers tapped
			}

			int get_ticketno()
			{
				return this->tiketnumb;
			}
};

#endif
