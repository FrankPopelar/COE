#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using std::cout;
using std::cin;
using std::endl;

// TRIANLGE STRUCTURE
struct tri
{
	float a;	// holds side a
	float b;	// holds side b
	float hyp;	// holds hypotenuse
	float angleA;	// holds angle opposite side a
	float angleB;	// holds angle opposite side b
};

float hyp(float a, float b)
{
	return sqrt(pow(a,2) + pow(b,2));
}

float angle(float a, float hyp)
{
	return asin(a/hyp) * 180 / M_PI;
}

int main()
{
	// VARIABLE INSTANTIATION
	float a1;			// holds the user inputs
	float b1;
	float a2;
	float b2;

	// INPUTS
	cout << "Enter side a for triangle 1: ";
	cin >> a1;
	cin.ignore();
	cout << "Enter side b for triangle 1: ";
	cin >> b1;
	cin.ignore();
	cout << "Enter side a for triangle 2: ";
	cin >> a2;
	cin.ignore();
	cout << "Enter side b for triangle 2: ";
	cin >> b2;
	cin.ignore();

	// METHOD
	tri tri1 = {a1, b1, hyp(a1, b1), angle(a1, hyp(a1, b1)), angle(b1, hyp(a1, b1))};
	tri tri2 = {a2, b2, hyp(a2, b2), angle(a2, hyp(a2, b2)), angle(b2, hyp(a2, b2))};

	// OUTPUTS
	cout << "Triangle 1: a = " << tri1.a << " b = " << tri1.b << " hypotenuse = " << tri1.hyp << endl << "angle 1 = " << tri1.angleA << " angle 2 = " << tri1.angleB << endl;
	cout << "Triangle 2: a = " << tri2.a << " b = " << tri2.b << " hypotenuse = " << tri2.hyp << endl << "angle 1 = " << tri2.angleA << " angle 2 = " << tri2.angleB << endl;
}
