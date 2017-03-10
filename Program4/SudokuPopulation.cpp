//
// Created by thuan on 09/03/17.
//

#include "SudokuPopulation.h"

int SudokuPopulation::bestFitness()
{
	int bestFit = theFit->howFit(container[0]);
	for ( Puzzle &x : container )
	{
		if ( bestFit < theFit->howFit(x))
		{
			bestFit = theFit->howFit(x);
		}
	}
	return bestFit;
}

Puzzle &SudokuPopulation::bestIndividual()
{
	int bestFit = theFit->howFit(container[0]);
	Puzzle * result;
	for ( Puzzle &x : container )
	{
		if ( bestFit < theFit->howFit(x))
		{
			
			bestFit = theFit->howFit(x);
			*result = x;
		}
	}
	return *result;
}

void SudokuPopulation::newGeneration()
{

}
