/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Sudoku class : A sudoku puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#include "SudokuFactory.h"

Puzzle * SudokuFactory::createPuzzle(Puzzle &thePuzzle)
{
	// Call the base class method since reproduction will create the puzzle
	return PuzzleFactory::createPuzzle(thePuzzle);
}

SudokuFactory::SudokuFactory(Reproduction &reproduction) : PuzzleFactory(reproduction)
{
	// Note that reproduction parameter will actually be SudokuOffspring
}
