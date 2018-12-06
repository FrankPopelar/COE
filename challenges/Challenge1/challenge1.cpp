//Challenge 1: fp4433
//Angles in degrees
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	//INPUTS
	double sidea;
	double sideb;
	cout << "Enter side a length: ";
	cin >> sidea;
	cout << "Enter side b length: ";
	cin >> sideb;
	double pi = 3.14159265359;

	//COMPUTATIONS
	double hyp = sqrt(pow(sidea,2) + pow(sideb,2));
	double anglea = asin(sidea/hyp) * 360 / (2 * pi);
	double angleb = asin(sideb/hyp) * 360 / (2 * pi);

	//OUTPUTS
	cout << "Hypotenuse value: "  << hyp << endl;
	cout << "Angle A is " << anglea << " degrees" << endl;
	cout << "Angle B is " << angleb << " degrees" << endl;
}
