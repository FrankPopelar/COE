#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	//VARIABLE INSTANTIATION
	vector<int> boo;			// holds the set of randomly generated numbers
	int r = 100.*rand() / RAND_MAX;		// holds the randomly generated number
	srand(time(0));				// sets the seed so it's not the same list every time	

	//BODY
	boo.push_back(r);			// sets the first value of boo
	while(boo.back() != 42)	// loops while the last element of boo is not 42
	{
		r = 100.*rand() / RAND_MAX;		// adds a random number to boo
		boo.push_back(r);
	}

	//OUTPUTS
	cout << "Length of boo: " << boo.size() << endl;
}
