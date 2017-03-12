/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of PuzzleFactory: PuzzleFactory will be the base class for SudokuFactory
 * PuzzleFactory is used to create new Puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#ifndef UNTITLED_PUZZLEFACTORY_H
#define UNTITLED_PUZZLEFACTORY_H


#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory
{
public:
	/*
	 * Constructor for the Puzzle Factory
	 * @param x a reproduction object used to reproduce Puzzle
	 */
	PuzzleFactory(Reproduction &x);
	
	/*
	 * Destructor for the factory
	 */
	virtual ~PuzzleFactory();
	
	/*
	 * This function is used to create new puzzle from the existing one
	 * @param thePuzzle the original puzzle to create
	 * @return a newly mutated Puzzle
	 */
	virtual Puzzle * createPuzzle(Puzzle &thePuzzle);

private:
	Reproduction* reproduc;
	





};


#endif //UNTITLED_PUZZLEFACTORY_H
