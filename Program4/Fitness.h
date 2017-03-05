//
// Created by thuan on 03/03/17.
//

#ifndef UNTITLED_FITNESS_H
#define UNTITLED_FITNESS_H

#include <iostream>
#include "Puzzle.h"

using namespace std;

class Fitness
{
public:
	Fitness();
	
	virtual int howFit(Puzzle &thePuzzle)  =0;
	
	
};


#endif //UNTITLED_FITNESS_H
