//
// Created by thuan on 07/03/17.
//

#include "SudokuFactory.h"

Puzzle * SudokuFactory::createPuzzle(Puzzle &thePuzzle)
{
	return PuzzleFactory::createPuzzle(thePuzzle);
}

SudokuFactory::SudokuFactory(Reproduction &reproduction) : PuzzleFactory(reproduction)
{

}
