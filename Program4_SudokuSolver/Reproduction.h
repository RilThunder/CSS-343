/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Reproduction class : Act as the base class to reproduce a puzzle.
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#ifndef UNTITLED_REPRODUCTION_H
#define UNTITLED_REPRODUCTION_H


#include "Puzzle.h"
#include <vector>
class Reproduction
{
public:
	/*
	 * This is the destructor for the Reproduction
	 */
	virtual ~Reproduction();
	
	/*
	 * This function is used to reproduce a Puzzle
	 * @param thePuzzle the originial Puzzle that need reproduction
	 * @return a pointer to the newly created Puzzle
	 */
	virtual Puzzle* makeOffspring(Puzzle &thePuzzle) = 0;
};


#endif //UNTITLED_REPRODUCTION_H
