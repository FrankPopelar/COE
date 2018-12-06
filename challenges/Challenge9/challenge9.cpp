#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<float> randomVector(int size)
{
	float temp;
	srand(time(NULL));
	vector<float> c;
	c.reserve(size);
	for(int i = 0; i < size; i++)
	{
		temp = 10. * rand() / RAND_MAX;
		c.push_back(temp);
	}
	return c;
}

void sort(vector<float> &c)
{
	float smallest;				// variable to hold the smallest value in the vector
	int position;				// holds the position of the nth smallest float
	for(int i = 0; i < c.size(); i++)
	{
		smallest = c[i];
		position = i;
		for(int j = i; j < c.size(); j++)
		{
			if(smallest > c[j])
			{
				smallest = c[j];
				position = j;
			}
		}
		c[position] = c[i];
		c[i] = smallest;
	}
}

int main()
{
	int length = 10;
	vector<float> values = randomVector(length);
	sort(values);
}
