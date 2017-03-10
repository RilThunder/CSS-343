//
// Created by thuan on 04/03/17.
//

#ifndef UNTITLED_REPRODUCTION_H
#define UNTITLED_REPRODUCTION_H


#include "Puzzle.h"
#include <vector>
class Reproduction
{
public:
	virtual Puzzle* makeOffspring(Puzzle &thePuzzle) = 0;
};


#endif //UNTITLED_REPRODUCTION_H
