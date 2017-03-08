//
// Created by thuan on 04/03/17.
//

#ifndef UNTITLED_SUDOKUOFFSPRING_H
#define UNTITLED_SUDOKUOFFSPRING_H


#include "Reproduction.h"

class SudokuOffspring : public Reproduction
{
	Puzzle * makeOffspring(Puzzle &thePuzzle);
	
};


#endif //UNTITLED_SUDOKUOFFSPRING_H
