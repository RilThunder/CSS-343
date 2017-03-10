//
// Created by thuan on 09/03/17.
//

#include <algorithm>
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"

int SudokuPopulation::bestFitness()
{
	int bestFit = theFit->howFit(*container[0]);
	for ( Puzzle * x : container )
	{
		if ( bestFit < theFit->howFit(*x))
		{
			bestFit = theFit->howFit(*x);
		}
	}
	return bestFit;
}

Puzzle &SudokuPopulation::bestIndividual()
{
	int bestFit = theFit->howFit(*container[0]);
	Puzzle * result;
	for ( Puzzle * x : container )
	{
		if ( bestFit < theFit->howFit(*x))
		{
			
			bestFit = theFit->howFit(*x);
			result = x;
		}
	}
	return *result;
}

void SudokuPopulation::newGeneration()
{
	if ( container.size() == 1 )
	{
		for ( int i = 1 ; i < size ; i++ )
		{
			container[i] = (reproduction->makeOffspring(*container[0]));
			return;
		}
	}
	int currentSize = container.size();
	int i = 0;
	int initialSize = currentSize;
	while ( currentSize < size )
	{
		if ( i == initialSize )
		{
			i = 0;
		}
		// keep making new Puzzle based on the remaing one
		container.push_back(reproduction->makeOffspring(*container[i]));
		i++;
		currentSize++;
	}
	
	
}

void SudokuPopulation::naturalSelection()
{
	vector<int> fitness[size];
	for ( int i = 0 ; i < size ; i++ )
	{
		fitness[0] = 0;
	}
	for ( int j = 0 ; j < size ; j++ )
	{
		fitness[j] = theFit->howFit(*container[j]);
	}
	// Sort the fitness , anything less than 90% range is eliminated
	// Sort in ascending order;
	sort(begin(fitness) , end(fitness));
	
	
}

SudokuPopulation::SudokuPopulation(Puzzle &thePuzzle , int theSize)
{
	reproduction = new SudokuOffspring();
	theFit = new SudokuFitness();
	size = theSize;
	factory = new SudokuFactory(*reproduction);
	*initialPuzzle = thePuzzle;
	
}
