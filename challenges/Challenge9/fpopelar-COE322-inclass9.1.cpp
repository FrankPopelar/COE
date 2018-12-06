#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

class Point
{
private:
	float x, y;	// holds the coordinates of the point
public:
	Point()	{ x = 0.0; y = 0.0; }	// default point constructor
	Point(float a, float b)		// secondary point ocnstructor
	{
		x = a; y = b;
	}
	float getx()			// getter for x
	{
		return x;
	}
	float gety()			// getter for y
	{
		return y;
	}
	float distance_to_origin()	// returns the distance to the origin
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	void printout()			// prints the point
	{
		cout << "X: " << x << endl << "Y: " << y << endl;
	}
	float distance(Point point2)	// distance from the current point to the inputted point
	{
		return sqrt(pow(x - point2.getx(), 2) + pow(y - point2.gety(), 2));
	}
};

int main()
{ 
	Point point1(3., 0.);
	Point point2(0., 4.);
	point1.printout();
	point2.printout();
	cout << "Distance from point 1 to origin: " << point1.distance_to_origin() << endl << "Distance from point 2 to origin: " << point2.distance_to_origin() << endl;
	cout << "Distance from point 1 to point 2: " << point1.distance(point2) << endl;
}
