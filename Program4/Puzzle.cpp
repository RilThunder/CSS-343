//
// Created by thuan on 01/03/17.
//

#include "Puzzle.h"

Puzzle::~Puzzle()
{

}

Puzzle::Puzzle()
{}

ostream &operator<<(ostream &output , const Puzzle &thePuzzle)
{
	thePuzzle.helpOutput(output);
	return output;
}

istream &operator>>(istream &input , Puzzle &theFile)
{
	theFile.helpInput(input);
	return input;
}

