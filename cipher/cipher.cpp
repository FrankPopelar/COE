// K-Shift Cipher
// Frank Popelar
// frank.popelar@gmail.com
// fp4433
// Last Change: 10/2/2018

#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void startup(bool initial);
void encrypt();
void decrypt();
void again();
bool punct(char punct, string standard);

int main()
{
	// VARIABLE INSTANTIATION
	bool initial = true;	// boolean to hold whether this is the first run
	
	
	// BODY
	startup(initial);	// really where most of the stuff is
}

void startup(bool initial)
{
	// VARAIBLE INSTANTIATION
	char encode;		// char to hold the user response for encryption or decryption
	
	// ENCRYPTION OR DECRYPTION
	if(initial)		// displays the welcome message, unecessary but nice
	{
		cout << "Welcome to the K-Shift Encryptor" << endl;
	}
	cout << "Would you like to encrypt or decrypt a message?" << endl << "E for encryption; D for decryption: ";
	cin >> encode;
	cin.ignore();

	if(encode == 'E' || encode == 'e')	// determining whether the program is encrypting or decrypting
	{
		encrypt();
		again();			// recursion function for rerunning the program
	}
	else if(encode == 'D' || encode == 'd')
	{
		decrypt();
		again();			// recursion function for rerunning the program
	}
	else
	{
		cout << "Invalid input, please try again" << endl;
		initial = false;
		startup(initial);
	}
}

void encrypt()
{
	// VARIABLE INSTANTIATION
	string message = "";		// holds the user's message
	int k;			// holds the user's k-shift
	string encrypted = "";	// holds the encrypted message
	char temp;		// holds the temporary char to be concatenated to the encrypted message
	bool done = false;	// holds the run condition for the while loop
	int count = 0;		// holds the count of the while loop
	string standard = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";	// holds the set of valid inputs

	// INPUTS
	cout << "Please enter the message you wish to encrypt: \n";	// obtains the user's message
	getline(cin, message);
	cout << "Please enter the k-shift you wish for encryption: ";		// obtains the k-shift for encryption
	cin >> k;
	cin.ignore();

	// ENCRYPTING
	for(int i = 0; i < message.length(); i++)
	{
		if(punct(message[i], standard))	// adds punctuation if that is at the point in message
		{
			encrypted += message[i];
		}
		else			// adds the encrypted character
		{
			for(int j = 0; j < standard.length(); j++)
			{
				if(message[i] == standard[j])
					temp = standard[(j + k) % standard.length()];
			}
			encrypted += temp;
		}
	}

	// OUTPUT
	cout << "Your encrypted message is:" << endl << encrypted << endl;
}

void decrypt()
{
	// VARIABLE INSTANTIATION
	string decoded = "";		// holds the decoded message
	string message = "";		// holds the user's message
	int k;				// holds the user's k-shift
	char temp;			// holds the temporary char to be concatenated to the decoded message
	string standard = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	// INPUTS
	cout << "Please enter your encrypted message: \n";		// obtains the user's message
	getline(cin,message);
	cout << "Please enter your k-shift: ";				// obtains the user's k-shift
	cin >> k;
	cin.ignore();
	
	// DECRYPTING
	for(int i = 0; i < message.length(); i++)
	{
		if(punct(message[i], standard))		// adds punctuation if that is at the point in the message
		{
			decoded += message[i];
		}
		else					// adds the decoded character
		{	
			for(int j = 0; j < standard.length(); j++)
			{
				if(standard[j] == message[i])
					temp = standard[(standard.length() - k + j) % standard.length()];
			}
			decoded += temp;
		}
	}
	// OUPUTS
	cout << "Your decrypted message is:" << endl << decoded << endl;
}

void again()
{
	// VARIABLE INSTANTIATION
	char rerun;		// char to hold whether the user wants to run the program again
	
	// BODY
	cout << "Would you like to run the program again? [Y/N] ";
	cin >> rerun;
	cin.ignore();

	if(rerun == 'Y' || rerun == 'y')
	{
		startup(false);
	}
	else if(rerun == 'N' || rerun == 'n')
	{
		cout << "Exitting . . ." << endl;
	}
	else
	{
		cout << "Invalid input, please try again" << endl;
		again();
	}
}

bool punct(char punct, string standard)
{
	// VARIABLE INSTANTIATION
	bool boo = true;		// returned boolean
	for(int i = 0; i < standard.length(); i++)
	{
		if(punct == standard[i])
			boo = false;
	}
	return boo;
}
