/*
 * Program 3: Implement Hash Functions for a phone book
 * Purpose HashPhone.cpp : Implement the Hash Function
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * February 12th, 2017
 * @version 1.1
 */



#include "HashPhone.h"

HashPhone::HashPhone()
{

}

HashPhone::~HashPhone()
{
	for ( int i = 0 ; i < SIZE ; i++ ) // Go through every element and delete
	{
		Entry * x = hashTable[i];
		Entry * next = x;
		while ( x != NULL )
		{
			x = x->nextEntry;
			delete next;
			next = x;
		}
	}
}


bool HashPhone::insert(string name , string number)
{
	Entry * newEntry = new Entry();
	newEntry->name = name;
	newEntry->number = number;
	int index = finalHash(name , atoi(number.c_str())) % SIZE; // Use the best hash function, can use other if you want
	Entry * target = hashTable[index];
	if ( target != NULL )
	{
		newEntry->nextEntry = target; // Put the new element at the top of the bucket
		
	}
	hashTable[index] = newEntry;
	return true;
}

long HashPhone::finalHash(string name , long number)
{
	unsigned result = 0;
	// compute the name first then the number
	for ( char x : name )
	{   // Quite interesting the number 33
		result = 33 * result + (x); // Use Hash Function by Dan Bernstein
		result = result % SIZE; // make sure it is not to big and overflow
	}
	string numberRepresent = to_string(number);
	for ( char x: numberRepresent )
	{
		result = 33 * result + (x - '0');
		result = result % SIZE;
		
	}
	return result;
}

long HashPhone::firstHash(string name , long number)
{
	long result = 0;
	for ( char x : name )
	{
		result = result + x - '0';
	}
	string numberRepresent = to_string(number);
	for ( char x: numberRepresent )
	{
		result = result + x - '0';
	}
	return result;
}

long HashPhone::secondHash(string name , long number)
{
	string result = "";
	for ( char x: name )
	{
		result = result + to_string(x);
		result = to_string(atoi(result.c_str()) % SIZE);
	}
	string numberRepresent = to_string(number);
	for ( char x: numberRepresent )
	{
		result = result + to_string(x - '0');
		result = to_string(atoi(result.c_str()) % SIZE);
	}
	return (long) atoi(result.c_str()); // Convert the string back to integer
}

void HashPhone::calculateVariance()
{
	// loop through the table to calculate frequency of each index
	for ( int i = 0 ; i < SIZE ; i++ )
	{
		Entry * x = hashTable[i];
		int count = 0;
		while ( x != NULL )
		{
			count++;
			x = x->nextEntry;
		}
		statistic.insert({i + 1 , count}); // To match with natural ordering
	}
	ofstream outfile;
	outfile.open("Variance.txt");
	double meanSquareError = 0;
	double x = AVERAGE;
	for ( int i = 1 ; i <= SIZE ; i++ )
	{
		meanSquareError = meanSquareError + pow((statistic.at(i) - x) , 2); // Mean Square Error
		
		outfile << to_string(i) + " " + to_string(statistic.at(i)) + "\n";
	}
	
	meanSquareError = meanSquareError / SIZE; // Pick the one with the lowest standard deviation
	outfile << "Variance is : " + to_string(sqrt(meanSquareError));
	
}





