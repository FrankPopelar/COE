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

class Population
{
private:
	int days = 0;
	vector<Person> pop;
public:
	Population(vector<Person> population)
	{
		pop = population;
	}
	int getDays() { return days; } // getter for days
	int update()
	{
		days++;
		int ans = 0;
		for(auto i:pop)
		{
			ans += i.update();
		}
		return ans;
	}
}	

int main()
{
	// VARIABLE INSTANTIATION
	srand(time(0));
	vector<Person> population(25, Person(0));
	int unlucky = 25.*rand()/RAND_MAX;
	population[unlucky] = Person(1);
	Population pop(population);
	int sick = 1;

	// SICK TIME
	while(sick != 0)
	{
		sick = pop.update();
		cout << "Day " << pop.getDays() << ": " << sick << " people sick" << endl;
	}
}
