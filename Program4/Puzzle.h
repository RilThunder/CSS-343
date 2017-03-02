//
// Created by thuan on 01/03/17.
//

#ifndef UNTITLED_PUZZLE_H
#define UNTITLED_PUZZLE_H
#include <iostream>
#include <fstream>
using namespace std;



class Puzzle
{
public:
	Puzzle();
	
	virtual ~Puzzle();
	
	/*
	 * This function is used to print out the content of the Puzzle
	 */
	virtual friend ostream& operator<<(ostream &output, const Puzzle &thePuzzle);
	
	
	/*
	 * This function is used to to create a puzzle from a text file
	 * @param theFile the file of the text file
	 */
	virtual friend ostream& operator>>(istream &input, const ofstream &theFile);
private:


};


#endif //UNTITLED_PUZZLE_H
