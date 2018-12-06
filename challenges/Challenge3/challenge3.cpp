//fp4433
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

float hypotenuse(float a, float b);
float angleA(float side, float hyp);
float angleB(float angle);

int main()
{
	//VARIABLE INSTANTIATION
	float a;		// user inputted side
	float b;		// user inputted side
	float hyp;		// hypotenuse
	float angle1;		// angle between b and hyp
	float angle2;		// anlge between a and hyp

	//INPUTS
	cout << "Enter side a length: ";
	cin >> a;
	cout << "Enter side b length: ";
	cin >> b;

	//COMPUTATIONS
	hyp = hypotenuse(a, b);
	angle1 = angleA(a, hyp);
	angle2 = angleB(angle1);
	
	//OUTPUTS
	cout << "Hypotenuse length: " << hyp << endl << "Angle 1: " << angle1 << endl << "Angle 2: " << angle2 <<  endl;
}

float hypotenuse(float a, float b)
{
	// FIND THE HYPOTENUSE GIVEN TWO SIDES
	float hyp = sqrt(pow(a,2) + pow(b,2));
	return hyp;
}

float angleA(float side, float hyp)
{
	// FINDS THE ANGLE OPPOSITE THE ENTERED SIDE
	float angle = asin(side/hyp) * (180.0 / M_PI);
	return angle;
}

float angleB(float angle)
{
	// FINDS THE LAST REMAINING ANGLE IN THE TRIANGLE
	float boo = 90 - angle;
	return boo;
}
