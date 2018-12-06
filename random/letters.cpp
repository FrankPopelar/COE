#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () 
{
	string word;
	string array_alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	word = word + array_alphabets [19] + array_alphabets [0] + array_alphabets [2] + array_alphabets [2] + array_alphabets [18] + array_alphabets [19] + array_alphabets [4] + array_alphabets [17];
	cout << word << endl;
}
