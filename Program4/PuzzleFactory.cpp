//
// Created by thuan on 07/03/17.
//

#include "PuzzleFactory.h"

PuzzleFactory::PuzzleFactory(Reproduction &x)
{
	reproduc = &x;
	
}

Puzzle * PuzzleFactory::createPuzzle(Puzzle &thePuzzle)
{
	return reproduc->makeOffspring(thePuzzle);
}
