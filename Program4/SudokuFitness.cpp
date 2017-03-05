//
// Created by thuan on 03/03/17.
//

#include <set>
#include "SudokuFitness.h"
#include "Sudoku.h"

int SudokuFitness::howFit(Puzzle &thePuzzle)
{
	Puzzle * target = &thePuzzle;
	int fitness = 0;
	Sudoku * x = dynamic_cast<Sudoku *> (target);
	vector<vector<int>> theVector = x->getSudoku();
	fitness = howFit(theVector);
	delete x;
	return fitness;
}


int SudokuFitness::howFit(vector<vector<int>> &x)
{
	int fitness = 0;
	
	// Note to self, using a bool array migh not work since the index
	set<int> validate;
	vector<vector<int>> theVector = x;
	// Check the fitness of each row
	for ( int row = 0 ; row < 9 ; row++ )
	{
		for ( int column = 0 ; column < 9 ; column++ )
		{
			int value = theVector[row][column];
			
			// Check to see if we encounter that variable before
			if ( validate.find(value) == validate.end())
			{
				fitness++;
			} else
			{
				// Set Flag
				validate.insert(value);
			}
		}
		
		// return to original
		validate.clear();
		
	}
	
	for ( int row = 0 ; row < 9 ; row++ )
	{
		for ( int column = 0 ; column < 9 ; column++ )
		{
			int value = theVector[column][row];
			// Check to see if we encounter that variable before
			if ( validate.find(value) == validate.end())
			{
				fitness++;
				
			} else
			{
				// Set Flag
				validate.insert(value);
			}
		}
		validate.clear();
	}
	for ( int row = 0 ; row < 9 ; row++ )
	{
		for ( int column = 0 ; column < 9 ; column++ )
		{
			// http://codereview.stackexchange.com/questions/46033/sudoku-checker-in-java
			int rowIndex = (row / 3) * 3 + column / 3;
			int columnIndex = (row * 3 % 9 + column % 3);
			
			
			int value = theVector[rowIndex][columnIndex];
			// Check to see if we encounter that variable before
			if ( validate.find(value) == validate.end())
			{
				fitness++;
				
			} else
			{
				// Set Flag
				validate.insert(value);
			}
		}
		
		validate.clear();
	}
	
	return fitness;
	
	
}

SudokuFitness::SudokuFitness()
{}


