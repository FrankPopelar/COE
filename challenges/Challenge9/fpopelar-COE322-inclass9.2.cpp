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

class Line
{
private:
	Point a;	// hold the point that make up the line
	Point b;
public:
	Line() { a = Point(); b = Point(); }	// default point constructor
	Line(Point point1, Point point2)	// secondary point constructor
	{
		a = point1; b = point2;
	}
	Line(float x, float y)			// tertiary point consstrucor
	{
		a = Point();
		b = Point(x,y);
	}
	Line(float x1, float y1, float x2, float y2)	// another point constructor
	{
		a = Point(x1, y1); b = Point(x2, y2);
	}
	void printout()			// prints the point
	{
		cout << "Point 1: " << endl; a.printout();
		cout << "Point 2: " << endl; b.printout();
	}
	Point midpoint()		// retuns the midpoint of the line
	{
		return Point((a.getx() + b.getx()) / 2, (a.gety() + b.gety()) / 2);
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

	Line line(point1, point2);
	line.printout();
	Line line2(2., 3., 4., 5.);
	line2.printout();
	line2.midpoint().printout();
}
