/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Reproduction class : Act as the base class to reproduce a puzzle.
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#include <random>
#include "Puzzle.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

Puzzle* SudokuOffspring::makeOffspring(Puzzle &thePuzzle)
{
	Puzzle * target = &thePuzzle;
	
	// Cast to the Sudoku type to use getSudoku method
	Sudoku * x = dynamic_cast<Sudoku * > (target);
	vector<vector<int>> theVector = x->getSudoku();
	
	// This will be the return Puzzle
	Sudoku *newPuzzle = new Sudoku();
	int prob = 0;
	// Prepare for random generator for mutation
	random_device rd;
	mt19937 mt(rd());
	// Probability if we want to mutate
	uniform_int_distribution<int> dist(1 , 100);
	// the new value that we will insert in if we mutate
	uniform_int_distribution<int> distribute(1 , 9);
	
	
	for (int i = 0; i < 9; i++)
	{
		
		for (int j =0 ; j < 9; j++)
		{
			
			prob = dist(mt);
			// THere is a 10& chance that we will mutate
			// Check to see if the value at that location is fixed or not
			bool isValue = x->isValue(i , j);
			
			if ( prob < 11 && !isValue )
			{
				
				int newValue = distribute(mt);
				
				// insert new value at that location to the Puzzle
				newPuzzle->insert(newValue , isValue , i , j);
				continue;
			}
			{
				// insert the same value
				newPuzzle->insert(theVector[i][j], isValue,i,j);
			}
			
		}
	}
	
	return newPuzzle;
}
