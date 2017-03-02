//
// Created by thuan on 01/03/17.
//

#include "Sudoku.h"

Sudoku::Sudoku()
{}

ostream &operator<<(ostream &os , const Sudoku &sudoku)
{
	os << static_cast<const Puzzle &>(sudoku);
	return os;
}
