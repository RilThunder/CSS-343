//
// Created by thuan on 01/03/17.
//

#ifndef UNTITLED_SUDOKU_H
#define UNTITLED_SUDOKU_H

#include <vector>

#include "Puzzle.h"

class Sudoku : public Puzzle
{
public:
	Sudoku();
	
	vector<vector<int>> getSudoku();

protected:
	void helpOutput(ostream &output) const;
	
	void helpInput(istream &input);


private:
	struct Entry
	{
		int value;
		bool isValue;
	};
	Entry representation[9][9];
	
	
};


#endif //UNTITLED_SUDOKU_H
