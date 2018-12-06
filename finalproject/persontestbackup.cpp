#include <iostream>
#include <random>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

class Person		// basic unit for population
{
private:
	int days;	// holds the number of days the person is sick for
	int status;	// holds the status of the person [0:susceptible|1:sick|2:recovered|3:immune]
public:
	Person()	// default person constructor
	{
		days = 0;
		status = 0;
	}
	Person(int s)	// secondary person constructor, where s is true if sick and i is true if immune
	{
		status = s;
		if(s == 1)
			days = 5;
		else
			days = 0;
	}
	int getStatus() { return status; }	// getter for status
	int getDays() { return days; }		// getter for days
	bool infect()	// infects a person, returns true if the person got sick and false otherwise
	{
		float r = 100.*rand()/RAND_MAX;
		if(r < 5)
		{
			status++;
			days = 5;
			return true;
		}
		return false;
	}
	int update()	// update function, returns 1 if a person is sick and 0 otherwise
	{
		if(status == 1)		// goes through one day for the person and adjusts days accordingly if they were sick
		{
			days--;
			if(days == 0)	// check to see if the person has recovered
				status = 2;
		}
		if(status == 0)		// check to see if the person is susceptible
		{
			if((*this).infect())		// tries to infect the person
				return 1;		// person got sick
			else
				return 0;		// person didn't get sick
		}
		else if(status == 1)	// check to see if the person is sick
			return 1;
		else
			return 0;	// otherwise the person is not sick
	}
			
};

int main()
{
	// VARIABLE INSTANTIATION
	srand(time(0));
	Person Joe(0);
	int iter = 0;
	
	// SICK TIME
	while(Joe.getStatus() == 0| Joe.getStatus() == 1)
	{
		iter++;
		Joe.update();
		switch(Joe.getStatus())
		{
			case 0: cout << "Day " << iter << ": Joe is susceptible" << endl;
				break;
			case 1: cout << "Day " << iter << ": Joe is sick with " << Joe.getDays() << " days to go" << endl;
				break;
			case 2: cout << "Day " << iter << ": Joe is recovered" << endl;
				break;
			case 3: cout << "Day " << iter << ": Joe is innoculated" << endl;
				break;
		}
	}
}
