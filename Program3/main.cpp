/*
 * Program 3: Implement Hash Functions for a phone boook
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
			lastname = result;
			result = "";
			continue;
		}
		if ( x == '(' || x == ')' || x == '-' )
		{
			if ( firstname == "" )
			{
				firstname = result;
				result = "";
			}
			continue;
		}
		if ( !isblank(x))
		{
			result = result + string(1 , x);
		}
	}
	
	thePhone.insert(firstname + " " + lastname , result);
	return;
}

int main()
{
	HashPhone * thePhone = new HashPhone();
	ifstream phonebook("phonebook.txt");
	string line = "";
	if ( phonebook.is_open())
	{
		while ( getline(phonebook , line)) // Process until the end of file
		{
			processString(line , *thePhone);
		}
		thePhone->calculateVariance();
		phonebook.close(); // Close the file when done
	} else
	{
		cout << "Unable to open file";
	}
	cout << "Finished";
	return 0;
}


