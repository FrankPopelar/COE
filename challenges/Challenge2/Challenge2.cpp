#include <iostream>
#include <time.h>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// VARIABLE CREATION
	int heads = 0;		// counts number of heads
	int tails = 0;		// counts number of tails	
	srand (time(NULL));	// setup for random variable creation
	int rand();

	//FLIPPING COINS
	for(int i = 0; i < 1000000; i++)
	{
		int random_number = rand();
		if (random_number % 2 == 0)
		{
			heads++;
		}
		else
		{	
			tails++;
		}
	}
	
	//OUTPUT
	cout << "HEADS: " << heads << endl << "TAILS: " << tails << endl;
}
