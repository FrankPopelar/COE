#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

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
	int infect(int rate)	// infects a person, returns 1 if the person got sick and 0 otherwise
	{
		float r = 100.*rand()/RAND_MAX;		// transmission random value
		if(r < rate)		// transmission check
		{
			status = 1;
			days = 6;	// in this case, days is set to be 6 because of the implementation of the Population update function to make sure that the person is sick for 5 full days
			return 1;
		}
		return 0;
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
	int sick = 0;			// holds the number of sick people in the population
	int rate = 1;			// holds the transmission rate as a percentage
	vector<Person> pop;		// Person vector for the population
public:
	Population(vector<Person> population)	// constructor for the population
	{
		pop = population;
	}
	int getDays() { return days; } 		// getter for days
	int getSick() { return sick; }		// getter for sick
	void setRate(int r) { rate = r; }	// updates the transmission rate
	int update()				// goes through a day, returns the total number of newly infected people
	{
		days++;			// increments days
		int ans = 0;		// holds the total number of sick people
		int pos = 0;		// holds the position in the vector
		int temp = 0;		// used to update the number of people currently sick
		for(auto i:pop)		// loops through each Person in the Population
		{
			if(i.getStatus() == 1)	// checks to see if the person is sick
			{
				for(int k = pos-5; k <= pos+5; k++)		// looks at the people closest to the infected person
				{
					if(pop[k % pop.size()].getStatus() == 0)	// check to see if the person is susceptible
					{
						ans += pop[k % pop.size()].infect(rate);	// if the person looked at is not susceptible, try to infect them
					}
				}
			}
			pos++;		// increment the position so we know where we are
		}
		for(auto &i:pop)	// updates everyone
		{
			temp += i.update();
		}
		sick = temp;
		return ans;
	}
	void flush()	// resets the population
	{
		days = 0;
		sick = 0;
	}
};

vector<Person> createPop(int size, int innoculated, int sick)	// creates a person vector with length size, number of innoculated people innoculated, and number of sick people sick [returns boo]
{
	int r;						// holds a randomly generated number
	vector<Person> boo(size, Person(0));		// creates an 'empty' person vector
	vector<int> inn;				// vector of positions available to be innoculated
	for(int i = 1; i <= size; i++)			// fills inn with numbers 1 to size
		inn.push_back(i);
	
	for(int i = 0; i < innoculated; i++)	// innoculates the specified number of people
	{
		r = inn.size() * 1. * rand() / RAND_MAX;
		boo[r].innoculate();
		inn.erase(inn.begin()+r);
	}
	for(int i = 0; i < sick; i++)		// infects the specified number of people
	{
		r = inn.size() * 1. * rand() / RAND_MAX;
		boo[r] = Person(1);
		inn.erase(inn.begin()+r);
	}

	return boo;
}

int main()
{
	//VARIABLE INSTANTIATION
	int popsize = 10000;		// number of people in the population
	int infected = 0;		// holds the maximum number of new people infected at each trial
	int trial = 0;			// the trial we are currently on
	int subtrial = 0;		// the subtrial we are currently on
	int results[2][100][95][30];	// holds the results [data, transmission rate, innoculation rate, trial] [data: 0 = number of days; 1 = number of new infected]
	bool first;			// used to determine whether the while loop has run at least once this subtrial
	float boo = 0;			// temporary variables used in writing to files
	float far = 0;

	//PRELIMS
	srand(time(0));			// sets the seed for the random vector to make sure that the program doesn't output the same results at each run
	for(int i = 0; i < 2; i++)	// set all values in array to be zero
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 95; k++)
			{
				for(int l = 9; l < 30; l++)
					results[i][j][k][l] = 0;
			}
		}
	}

	//SICK TIME
	for(int i = 1; i < 100; i++)			// loops through the transmission rates
	{
		for(int j = 1; j < 96; j++)		// loops through the innoculation percentages
		{
			cout << "Iteration " << i << ", " << j << endl;
			for(int k = 0; k < 30; k++)	// loops through the subtrials
			{
				first = true;
				Population pop(createPop(popsize, j*100, 50));	// creates the new population with the specified parameters
				pop.setRate(i);					// sets the transmission rate for the current iteration
				while(pop.getSick() != 0 || first)		// loops through the population
				{
					first = false;					// not the first trial if it's run
					results[1][i-1][j-1][k] += pop.update();	// records the number of newly infected people
				}
				results[0][i-1][j-1][k] = pop.getDays();		// records the number of days the disease existed for
				pop.flush();						// empties the values in pop, I don't know if this is necessary, but it makes me feel good
			}
		}
	}
	
	cout << "Printing to file" << endl;
	//PRINTING TO FILE
	ofstream f;			// output file stream for the days file
	f.open("days.txt");		// open file days [output file stream, so write to file already enabled]
	ofstream g;			// output file stream for the infections file
	g.open("infect.txt");		// same as above but for infect file
	f << "Transmission rate explicitly defined as it changes, innoculation rate varies from 1 to 95 in the list, but are not explicitly stated for ease of copying and pasting\n";
	g << "Transmission rate explicitly defined as it changes, innoculation rate varies from 1 to 95 in the list, but are not explicitly stated for ease of copying and pasting\n";
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			boo = 0;
			far = 0;
			for(int k = 0; k < 30; k++)
			{
				boo += results[0][i][j][k];
				far += results[1][i][j][k];
			}
			f << boo/30 << "\n";
			g << far/30 << "\n";
		}
	}
}
