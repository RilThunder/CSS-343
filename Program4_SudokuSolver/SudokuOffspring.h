/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Reproduction class : Act as the base class to reproduce a puzzle.
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#ifndef UNTITLED_SUDOKUOFFSPRING_H
#define UNTITLED_SUDOKUOFFSPRING_H


#include "Reproduction.h"

class SudokuOffspring : public Reproduction
{
public:
	/*
	 * This function is used to reproduce a Sudoku object
	 * @param thePuzzle the Sudoku puzzle that we want to reproduce
	 * @return a pointer to the newly created Puzzle (base class)
	 */
	Puzzle * makeOffspring(Puzzle &thePuzzle);
	
};


#endif //UNTITLED_SUDOKUOFFSPRING_H
