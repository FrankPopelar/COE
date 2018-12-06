//Challenge 1: fp4433
//Angles in degrees
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

void calc(double a, double b, double &h, double &ang1, double &ang2);

int main()
{
	//INPUTS
	double sidea;
	double sideb;
	double hyp;
	double angle1;
	double angle2;
	cout << "Enter side a length: ";
	cin >> sidea;
	cout << "Enter side b length: ";
	cin >> sideb;

	//COMPUTATIONS
	calc(sidea, sideb, hyp, angle1, angle2);

	// OUTPUTS
	cout << "Hypotenuse Length: " << hyp << endl;
	cout << "Angle 1: " << angle1 << endl;
	cout << "Angle 2: " << angle2 << endl;
}

void calc(double a, double b, double &h, double &ang1, double &ang2)
{
	h = sqrt(pow(a,2) + pow(b,2));
	ang1 = asin(a/h) * 180 / M_PI;
	ang2 = asin(b/h) * 180 / M_PI;
}
