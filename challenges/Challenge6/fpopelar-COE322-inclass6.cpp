#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

void fib(int count, int elder, int old, int iterations);

int main()
{
	int iterations;
	cout << "Enter the number of Fibonacci numbers to calculate: ";
	cin >> iterations;
	cout << "0 1 ";
	fib(0, 0, 1, iterations - 2);
}

void fib(int count, int elder, int old, int iterations)
{
	int current;
	if(count < iterations)
	{
		count++;
		current = old + elder;
		elder = old;
		old = current;
		cout << current << " ";
		fib(count, elder, old, iterations);
	}
	else
	{
		cout << endl;
	}
}
