
/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Puzzle class : Act as the base class for Sudoku.
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */
#include "Puzzle.h"

Puzzle::~Puzzle()
{

}

Puzzle::Puzzle()
{}

ostream &operator<<(ostream &output , const Puzzle &thePuzzle)
{
	// Will use the overided method in subclass
	thePuzzle.helpOutput(output);
	return output;
}

istream &operator>>(istream &input , Puzzle &puzzle)
{
	puzzle.helpInput(input);
	return input;
}

