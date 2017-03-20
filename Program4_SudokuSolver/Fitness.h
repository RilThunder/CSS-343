
/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Fitness class : Act as the base class to assest the fitness of a Puzzle.
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */
#ifndef UNTITLED_FITNESS_H
#define UNTITLED_FITNESS_H

#include <iostream>
#include "Puzzle.h"

using namespace std;

class Fitness
{
public:
	/*
	 * This is the default constructor. Never used
	 */
	Fitness();
	
	/*
	 * This function is used to assest how fit a Puzzle is
	 * @param thePuzzle the Puzzle to assest
	 * @return an integer represent the fitness. THe lower the better
	 */
	virtual int howFit(Puzzle &thePuzzle)  =0;
	
	
};


#endif //UNTITLED_FITNESS_H
