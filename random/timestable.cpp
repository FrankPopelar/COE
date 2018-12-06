#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	//VARIABLE INSTANTIATION
	int table [9];		// array containing 1 through 9
	int temp;		// variable for temporary output storage

	//TABLE POPULATION
	for(int i = 1; i < 10; i++)
	{
		table[i] = i;
	}
	
	//OUTPUT
	for(int i = 1; i < 10; i++)
	{
		for(int j = 1; j < 10; j++)
		{
			temp = table[i] * table[j];
			cout << temp;
			if(temp < 10)
			{
				cout << "  ";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
