#ifndef __Station_H
#define __Station_H

class Station
{
	string Station_name;
	Wagon *transiting_train;
	deque<Person> people; 
	
	public:
		Station(string name)
		{
			this->Station_name = name;
			cout<< "STATION " << this->Station_name << " CREATED" <<endl;
		}
		void Accept_train(Wagon train)
		{
			this->transiting_train= &train;
		}
};

#endif 
