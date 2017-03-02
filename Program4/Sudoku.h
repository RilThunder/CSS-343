//
// Created by thuan on 01/03/17.
//

#ifndef UNTITLED_SUDOKU_H
#define UNTITLED_SUDOKU_H

#include <ostream>
#include "Puzzle.h"

class Sudoku: public Puzzle
{

private:

public:
	Sudoku();
	
	friend ostream &operator<<(ostream &os , const Puzzle &sudoku);
	
	
	
};


#endif //UNTITLED_SUDOKU_H
