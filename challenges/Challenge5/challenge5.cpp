#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

void squares(int count, int old, int total, int iterations);

int main()
{
	squares(0, 0, 0, 100);
}

void squares(int count, int old, int total, int iterations)
{
	if(count <= iterations)
	{
		count++;
		total = old + pow(count, 2);
		old = total;
		cout << total << " ";
		squares(count, old, total, iterations);
	}
	else
	{
		cout << endl;
	}
}
