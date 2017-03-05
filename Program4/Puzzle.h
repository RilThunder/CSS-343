//
// Created by thuan on 01/03/17.
//

#ifndef UNTITLED_PUZZLE_H
#define UNTITLED_PUZZLE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Puzzle
{
public:
	Puzzle();
	
	virtual ~Puzzle();
	
	friend ostream &operator<<(ostream &output , const Puzzle &thePuzzle);
	
	friend istream &operator>>(istream &input , Puzzle &theFile);
	
	virtual void helpOutput(ostream &output) const = 0;
	
	virtual void helpInput(istream &input) = 0;


/*
protected:
	virtual void helpOutput(ostream &output) const;
	virtual void helpInput(istream &input);
	*/
	
};


#endif //UNTITLED_PUZZLE_H
