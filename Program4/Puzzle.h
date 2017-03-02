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
	
	friend ostream& operator<<(ostream &output, const Puzzle &thePuzzle);
	
	friend istream& operator>>(istream &input, Puzzle &theFile);

protected:
	virtual void helpOutput(ostream &output) const;
	virtual void helpInput(istream &input);
	



};


#endif //UNTITLED_PUZZLE_H
