//
// Created by thuan on 07/03/17.
//

#ifndef UNTITLED_PUZZLEFACTORY_H
#define UNTITLED_PUZZLEFACTORY_H


#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory
{
public:
	PuzzleFactory(Reproduction &x);
	
	
	virtual Puzzle * createPuzzle(Puzzle &thePuzzle);

private:
	Reproduction* reproduc;
	





};


#endif //UNTITLED_PUZZLEFACTORY_H
