

#include <cstdio>
#include "HashPhone.h"

HashPhone::HashPhone()
{}

HashPhone::~HashPhone()
{

}


bool HashPhone::insert(string name , int number)
{
	Entry * newEntry = new Entry();
	newEntry->name = name;
	newEntry->number = number;
	int index = (int) (finalHash(name , number) % SIZE);
	Entry * target = hashTable[index];
	if ( target != NULL )
	{
		newEntry->nextEntry = target; // Put the new element at the top of the bucket
		
	}
	hashTable[index] = newEntry;
	return true;
}

long HashPhone::finalHash(string name , int number)
{
	unsigned result = 0;
	for ( char x : name )
	{
		result = 33 * result + (x - '0');
	}
	string numberRepresent = to_string(number);
	for ( char x: numberRepresent )
	{
		result = 33 * result + (x - '0');
		
	}
	return result;
}

long HashPhone::firstHash(string name , int number)
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

long HashPhone::secondHash(string name , int number)
{
	string result = "";
	for ( char x: name )
	{
		result = result + to_string(x);
		
	}
	string numberRepresent = to_string(number);
	for ( char x: numberRepresent )
	{
		result = result + to_string(x);
	}
	return (long) atoi(result.c_str()); // Convert the string back to integer
}





