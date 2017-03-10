//
// Created by thuan on 07/03/17.
//

#ifndef UNTITLED_SUDOKUFACTORY_H
#define UNTITLED_SUDOKUFACTORY_H


#include "Puzzle.h"
#include "Reproduction.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory
{
public:
	SudokuFactory(Reproduction &reproduction);
	
	virtual Puzzle * createPuzzle(Puzzle &thePuzzle);
	
};


#endif //UNTITLED_SUDOKUFACTORY_H
