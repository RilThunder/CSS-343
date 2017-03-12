/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Sudoku class : A sudoku puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#ifndef UNTITLED_SUDOKU_H
#define UNTITLED_SUDOKU_H

#include <vector>

#include "Puzzle.h"

class Sudoku : public Puzzle
{
public:
	/*
	 * The default constructor for a sudoku object
	 */
	Sudoku();
	
	/*
	 * This method is used to get the sudoku in a 2D representation (row and column)
	 *
	 */
	vector<vector<int>> getSudoku();
	
	/*
	 * This i used
	 */
	void helpOutput(ostream &output) const;
	
	void helpInput(istream &input);

	void insert(int value, bool isValue, int row, int column);
	
	bool isValue(int row, int column);

private:
	struct Entry
	{
		int value;
		bool isValue;
	};
	Entry representation[9][9];
	
	
};


#endif //UNTITLED_SUDOKU_H
