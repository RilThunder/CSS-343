//
// Created by thuan on 09/03/17.
//

#include "Population.h"

Population::Population(Fitness &theFitness , Reproduction &repro , Puzzle &thePuzzle , PuzzleFactory &theFactory ,
                       int theSize)
{
	*theFit = theFitness;
	*reproduction = repro;
	*initialPuzzle = thePuzzle;
	*factory = theFactory;
	container[0] = thePuzzle;
	size = theSize;
	newGeneration();
	
}

