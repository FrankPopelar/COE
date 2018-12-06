#include <iostream>
#include <random>
#include <time.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
	Person(int s)	// secondary person constructor, where s is the status of the person
	{
		status = s;
		if(status == 1)		// sets days for the appropriate status of the population
			days = 5;
		else
			days = 0;
	}
	int getStatus() { return status; }	// getter for status
	int getDays() { return days; }		// getter for days
	int innoculate()	// immunizes a person
	{
		status = 3;
		return 1;
	}
	bool infect()	// infects a person, returns true if the person got sick and false otherwise
	{
		float r = 100.*rand()/RAND_MAX;
		if(r < 5)
		{
			status = 1;
			days = 5;
			return true;
		}
		return false;
	}
	int update()	// update function, returns 1 if a person is sick and 0 otherwise
	{
		if(status != 1)	// check to see if person is sick
			return 0;
		else		// goes through one day for the person and adjusts days accordingly if they were sick
		{
			days--;		// decrements number of days the person is sick for
			if(days == 0)	// check to see if the person has recovered
			{
				status = 2;
				return 0;	// returns 0 if the person recovered
			}
			return 1;	// returns one if the person is sick
		}
	}
			
};

class Population
{
private:
	int days = 0;			// holds the number of days the population has run for
	vector<Person> pop;		// Person vector for the population
public:
	Population(vector<Person> population)	// constructor for the population
	{
		pop = population;
	}
	int getDays() { return days; } 	// getter for days
	int update()			// goes through a day, returns the total number of sick people
	{
		days++;			// increments days
		int ans = 0;		// holds the total number of sick people
		int pos = 1;		// holds the position in the vector
		for(auto i:pop)		// loops through each Person in the Population
		{
			if(i.getStatus() == 1)	// checks to see if the person is sick
			{
				for(int k = pos-3; k <= pos+3; k++)
				{
					if(pop[k % pop.size()].getStatus() == 0 && k != pos)
					{
						pop[k % pop.size()].infect();
						cout << "Infecting " << k % pop.size() << " . . ." << endl;
					}
				}
			}
			pos++;
		}
		for(auto &i:pop)
		{
			ans += i.update();
			cout << i.getStatus() << " ";
		}
		cout << endl;
		return ans;
	}
};

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
