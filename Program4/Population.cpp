
/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Population class : Act as the base class for SudokuPopulation.
 * A container for all the Puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */
#include "Population.h"


Population::~Population()
{

}

Population::Population()
{
	theFit = NULL;
	reproduction = NULL;
	initialPuzzle = NULL;
	factory = NULL;
	
	size = 0;
}
