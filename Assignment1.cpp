/*a. Scott Cummings
	b. 2317991
	c. scummings@chapman.edu
	d. CPSC 350 - Section 01
	e. Assignment 1
	Overview: The main function of the program. Contains most of the implementation for use of the command
	line argument.
	*/
#include <iostream> //cout/cin
#include <string> // using strings

#include "DNA_String.h" //my DNA class header file

using namespace std;
int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Please enter a command line argument for the file you would like to check." << endl;
		exit(0);
	}
	char response = ' ';
	string outputFileName;
	string inputFileName;
	cout << "What would you like your output file to be called? ";
	cin >> outputFileName;
	cout << "\n";
	DNA_String someDNAString;
	someDNAString.generateInfo(argv[1], outputFileName);
	while (true) {
	cout << "Would you like to check another file?(y/n)" << endl;
	cin >> response;
	while (response != 'y' && response != 'n') {
		cout << "User input not recognized. Please enter 'y' to check against another file, or 'n' to exit the program!" << endl;
		cin >> response;}
	if (response == 'y')
	{
		cout << "What is the name of the file you would like to generate stats for? ";
		cin >> inputFileName;
		cout << "\n" << "What would you like your output file to be called? ";
		cin >> outputFileName;
		cout << "\n";
		DNA_String newDNAString;
		newDNAString.generateInfo(inputFileName,outputFileName);
		response = ' ';
	}
	else if (response == 'n')
	{
		cout << "Thank you for using the Nucleotide stats generator!" << endl;
		exit(0);
	}
	else
	{
		cout << "Sorry, input not recognized, be sure to responde either with \'y\' or \'n\'" << endl;
	}
}
		return 0;
		}
