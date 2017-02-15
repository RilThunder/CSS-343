


#include "HashPhone.h"

HashPhone::HashPhone()
{

}

HashPhone::~HashPhone()
{

}


bool HashPhone::insert(string name , string number)
{
	Entry * newEntry = new Entry();
	newEntry->name = name;
	newEntry->number = number;
	int index = finalHash(name , atoi(number.c_str())) % SIZE;
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
	for ( char x : name )
	{
		result = 33 * result + (x);
		result = result % SIZE;
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
		
	}
	string numberRepresent = to_string(number);
	for ( char x: numberRepresent )
	{
		result = result + to_string(x);
	}
	return (long) atoi(result.c_str()); // Convert the string back to integer
}

void HashPhone::calculateVariance()
{
	for ( int i = 0 ; i < SIZE ; i++ )
	{
		Entry * x = hashTable[i];
		int count = 0;
		while ( x != NULL )
		{
			count++;
			x = x->nextEntry;
		}
		statistic.insert(i + 1 , count); // To match with natural ordering
	}
	ofstream outfile("Variance.txt");
	double meanSquareError;
	for ( int i = 1 ; i <= SIZE ; i++ )
	{
	
	}
	
}





