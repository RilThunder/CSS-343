/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of PuzzleFactory: PuzzleFactory will be the base class for SudokuFactory
 * PuzzleFactory is used to create new Puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#include "PuzzleFactory.h"

PuzzleFactory::PuzzleFactory(Reproduction &x)
{
	reproduc = &x;
	
}

Puzzle * PuzzleFactory::createPuzzle(Puzzle &thePuzzle)
{
	// Call the function of the base class
	return reproduc->makeOffspring(thePuzzle);
}

PuzzleFactory::~PuzzleFactory()
{

}
