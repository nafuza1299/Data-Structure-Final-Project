#ifndef __SEAT_H
#define __SEAT_H

using namespace std;
//Creates 'seat' based on ticket number
//Used to check if space is available
class Seat
{
	
	int number;
	
    
	public:
		Person people;
		bool avail;	
		Seat(int no)
		{
			
			this->avail=true;
			this->number=no;	
            cout<<"Seat #"<<this->number<< " is constructed"<<endl;
		}
		Seat(){}
		void set_occupied() //sets availability to false
		{
			this->avail=false;
		}
		void set_free() //sets availability to true
		{
			this->avail=true;
		}
		void set_people(Person come_in) //container for the passengers
		{
			this->people=come_in;
		}
		int get_number()
		{
			return this->number;
		}
		Person get_person()
		{
			return this->people;
		}
		
};


#endif
