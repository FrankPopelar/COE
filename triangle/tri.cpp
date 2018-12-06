#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

class Triangle
{
private:
	float a, b;	// hold the side lengths of the right triangle
public:
	Triangle() { a = 1.; b = 1.; }	// default triangle constructor
	Triangle(float side1, float side2)	// secondary triangle constructor
	{
		a = side1; b = side2;
	}
	float geta() { return a; }	// getter for side a
	float getb() { return b; } 	// getter for side b
	float hyp()			// returns the hypotenuse length
	{
		return sqrt(pow(a, 2) + pow(b, 2));
	}
	float angleA()			// returns the angle next to side a
	{
		return acos(a / (*this).hyp()) * 180. / M_PI;
	}
	float angleB()			// returns the angle next to side b
	{
		return acos(b / (*this).hyp()) * 180. / M_PI;
	}
	void printout()			// displays the triangle
	{
		cout << "Side A: " << a << endl << "Side B: " << b << endl << "Hypotenuse: " << (*this).hyp() << endl;
		cout << "Angle A: " << (*this).angleA() << endl << "Angle B : " << (*this).angleB() << endl;
	}
};

int main()
{
	Triangle tri(3., 4.);
	tri.printout();
}
