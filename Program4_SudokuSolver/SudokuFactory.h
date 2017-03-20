/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of SudokuFactory: SudokuFactory will be used to create Sudoku Puzzle
 *
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#ifndef UNTITLED_SUDOKUFACTORY_H
#define UNTITLED_SUDOKUFACTORY_H


#include "Puzzle.h"
#include "Reproduction.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory
{
public:
	/*
	 * This is the constructor for the SudokuFactory
	 * @param reproduction the Reproduction object (SudokuOffspring)
	 */
	SudokuFactory(Reproduction &reproduction);
	
	/*
	 * This function is used to create new Puzzle(Sudoku)
	 * @param the original Puzzle to reproduce
	 * @return a pointer to the newly created puzzle
	 */
	Puzzle * createPuzzle(Puzzle &thePuzzle);
	
};


#endif //UNTITLED_SUDOKUFACTORY_H
