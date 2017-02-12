/*
 *  @author Thuan Tran
 *  Date: February 11th,2017
 *  HashPhone.h
 *  Purpose: Implement several hash functions and determine which one the best
 *  Given 46,332 names and phone numbers, try to distribute them on 4177 entries
 */



#ifndef PROGRAM3_HASHPHONE_H
#define PROGRAM3_HASHPHONE_H


class HashPhone
{
	/*
	 * This struct will be used as a chain to hold the name and phone number
	 * At a particular index
	 */
	struct Entry
	{
		string name;
		long number;
		Entry * nextEntry;
	};
public:
	/*
	 * This is an empty constructor
	 */
	HashPhone();
	
	/*
	 * This is the destructor
	 */
	~HashPhone();
	
	/*
	 * This function is used to insert into the hashTable
	 * @param name the name of the person
	 * @param number the phone number
	 *
	 */
	int insert(string name , int number);

private:
	const int SIZE = 4177; // Size of the array
	Entry * hashTable[SIZE];
	
	/*
	 * This is an experiement hash function
	 * It create the index where to put the Entry
	 * Method: Add every char value in name in its original format (Not converted to decimal)
	 * Then add every number in number
	 */
	int firstHash(string name , int number);
	
	/*
	 * This is an experiment hash function
	 * Method: Append every char value in name and number (String concatination)
	 */
	int secondHash(string name , int number);
	
	/*
	 * Final method
	 * Method: Turn every char value in name in to binary form, the same as number
	 * Concatinate all of them together
	 */
	int finalHash(string name , int number);
};


#endif //PROGRAM3_HASHPHONE_H
