//
// Created by thuan on 04/03/17.
//

#include "Puzzle.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

Puzzle* SudokuOffspring::makeOffspring(Puzzle &thePuzzle)
{
	Puzzle * target = &thePuzzle;
	int fitness = 0;
	Sudoku * x = dynamic_cast<Sudoku *> (target);
	vector<vector<int>> theVector = x->getSudoku();
	Sudoku *newPuzzle = new Sudoku();
	int prob = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j =0 ; j < 9; j++)
		{
			prob = rand() % 100;
			// Fall into the 5% category
			bool isValue = newPuzzle->isValue(i,j);
			if (prob < 5)
			{
				
				// insert new value at that location to the Puzzle
				newPuzzle->insert(rand() % 9 +1, isValue , i,j);
			}
			else
			{
				newPuzzle->insert(theVector[i][j], isValue,i,j);
			}
			
		}
	}
	delete x;
	return newPuzzle;
}
