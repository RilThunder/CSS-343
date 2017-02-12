

#include <cstdio>
#include "HashPhone.h"

HashPhone::HashPhone()
{}

HashPhone::~HashPhone()
{

}

int HashPhone::hash()
{
	return 0;
}

int HashPhone::insert(string name , int number)
{
	Entry * newEntry = new Entry();
	newEntry->name = name;
	newEntry->number = number;
	int index = finalHash(nullptr , 0);
	Entry * target = hashTable[index];
	if ( target != NULL )
	{
		newEntry->nextEntry = target;
		
	}
	hashTable[index] = newEntry;
}

int HashPhone::finalHash(string name , int number)
{
	return 0;
}

int HashPhone::firstHash(string name , int number)
{
	long result = 0;
	for ( char x : name )
	{
		result = result + x;
	}
	return (int) result % SIZE;
}

int HashPhone::secondHash(string name , int number)
{
	return 0;
}





