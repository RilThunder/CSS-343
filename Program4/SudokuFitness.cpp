/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of SudokuFitness class : Asset the fitness of a sudoku puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#include <set>
#include "SudokuFitness.h"
#include "Sudoku.h"

int SudokuFitness::howFit(Puzzle &thePuzzle)
{
	
	int fitness = 0;
	Sudoku * x = dynamic_cast<Sudoku *> (&thePuzzle);
	// get the represent tation
	vector<vector<int>> theVector = x->getSudoku();
	fitness = howFit(theVector);
	
	return fitness;
}


int SudokuFitness::howFit(vector<vector<int>> &x)
{
	int fitness = 0;
	
	// the set is used to check for duplicate in the row, column or block (3x3)
	set<int> validate;
	vector<vector<int>> theVector = x;
	// Check the fitness of each row
	for ( int row = 0 ; row < 9 ; row++ )
	{
		for ( int column = 0 ; column < 9 ; column++ )
		{
			int value = theVector[row][column];
			
			// Check to see if we encounter that variable before
			if ( validate.find(value) != validate.end())
			{
				// it already existed => not good
				fitness++;
			} else
			{
				
				validate.insert(value);
			}
		}
		
		// return to original after every row, column or block
		validate.clear();
		
	}
	// check the fitness of each column
	for ( int row = 0 ; row < 9 ; row++ )
	{
		for ( int column = 0 ; column < 9 ; column++ )
		{
			int value = theVector[column][row];
			// Check to see if we encounter that variable before
			if ( validate.find(value) != validate.end())
			{
				fitness++;
				
			} else
			{
				// Set Flag
				validate.insert(value);
			}
		}
		// reset
		validate.clear();
	}
	
	// check the fitness of each block
	for ( int row = 0 ; row < 9 ; row++ )
	{
		for ( int column = 0 ; column < 9 ; column++ )
		{
			// Formula to traverse the block
			// Source
			// http://codereview.stackexchange.com/questions/46033/sudoku-checker-in-java
			int rowIndex = (row / 3) * 3 + column / 3;
			int columnIndex = (row * 3 % 9 + column % 3);
			
			
			int value = theVector[rowIndex][columnIndex];
			// Check to see if we encounter that variable before
			if ( validate.find(value) != validate.end())
			{
				fitness++;
				
			} else
			{
				// Set Flag
				validate.insert(value);
			}
		}
		//reset
		validate.clear();
	}
	
	return fitness;
	
	
}

SudokuFitness::SudokuFitness()
{}


