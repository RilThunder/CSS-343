/*
 * Program 3: Implement Hash Functions for a phone book
 * Purpose main.cpp : Driver and process the input
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * February 12th, 2017
 * @version 1.1
 */


#include <iostream>
#include <fstream>

#include "HashPhone.h"

using namespace std;


void processString(string line , HashPhone &thePhone)
{
	string result = "";
	string firstname = "";
	string lastname = "";
	for ( char x: line )
	{
		if ( x == ',' )
		{
			lastname = result; // ok we finished the last name
			result = "";
			continue;
		}
		if ( x == '(' || x == ')' || x == '-' )
		{
			if ( firstname == "" ) // if we reach this part of number, we finished the first name
			{
				firstname = result;
				result = "";
			}
			continue;
		}
		if ( !isblank(x))
		{
			// append everything else
			result = result + string(1 , x);
		}
	}
	// By this point, result should be the phone number
	thePhone.insert(firstname + " " + lastname , result);
	return;
}

int main()
{
	cout << "There are 3 hash functions in this program" << endl;
	cout << "The one I used is the final one, but you can change it to the other two" << endl;
	cout << "I also included a method that will create text files that show the distribution and variance of the hash";
	HashPhone * thePhone = new HashPhone();
	ifstream phonebook("phonebook.txt");
	string line = "";
	if ( phonebook.is_open())
	{
		while ( getline(phonebook , line)) // Process until the end of file
		{
			processString(line , *thePhone);
		}
		// Uncomment the part below to calculate the variance and receive a text file to show the distribution
		// You can also change the insert function in HashPhone.cpp and run again to see different result
		// Only need to change the name of the method finalHash to firstHash or secondHash in insert
		
		
		//thePhone->calculateVariance();
		phonebook.close(); // Close the file when done
	} else
	{
		cout << "Unable to open file";
	}
	delete thePhone;
	cout << "Finished";
	return 0;
}


