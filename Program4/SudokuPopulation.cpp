
/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of SudokuPopulation class : A container for all the Sudoku
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */
#include <algorithm>
#include <vector>
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"

int SudokuPopulation::bestFitness()
{
	// loop through all the puzzle in container and save the best one
	int bestFit = theFit->howFit(*container[0]);
	for ( Puzzle * x : container )
	{
		int newFit = theFit->howFit(*x);
		if ( newFit < bestFit )
		{
			bestFit = theFit->howFit(*x);
		}
	}
	return bestFit;
}

Puzzle &SudokuPopulation::bestIndividual()
{
	// Loop through the container and save the best one
	int bestFit = theFit->howFit(*container[0]);
	Puzzle * result = container[0];
	for ( Puzzle * x : container )
	{
		if ( theFit->howFit(*x) < bestFit )
		{
			
			bestFit = theFit->howFit(*x);
			result = x;
		}
	}
	return *result;
}

void SudokuPopulation::newGeneration()
{
	// Create new member from the population based on the initial Puzzle
	if ( container.size() == 1 )
	{
		for ( int i = 1 ; i < size ; i++ )
		{
			Puzzle * x = factory->createPuzzle(*container[0]);
			//	cout << endl;
			//	cout << *x;
			//cout << endl;
			container.push_back(x);
			
		}
		return;
	}
	// Create new puzzle until we reach the size
	int currentSize = container.size();
	int i = 0;
	
	int initialSize = currentSize;
	
	while ( currentSize < size )
	{
		if ( i == initialSize )
		{
			// Create new puzzle based on the first remaining puzzle
			// For example, if we have 5 puzzle left, then we alternate create new puzzle on those five
			i = 0;
		}
		// keep making new Puzzle based on the remaing one
		container.push_back((factory->createPuzzle(*container[i])));
		i++;
		currentSize++;
	}
	
	
}

void SudokuPopulation::naturalSelection()
{
	int fitness[size] = {0};
	for ( int j = 0 ; j < size ; j++ )
	{
		fitness[j] = theFit->howFit(*container[j]);
	}
	// Sort the fitness , anything less than 90% range is eliminated
	// Sort in ascending order;
	sort(fitness , fitness + size , greater<int>());
	int mark = (size * 9) / 10 - 1;
	
	// Sort the vector in descending order of fitness using lambda expression
	sort(container.begin() , container.end() , [this](auto &lhs , auto &rhs)
	{
		return theFit->howFit(*lhs) > theFit->howFit(*rhs);
	});

	// everything below the mark is deleted
	for ( int i = 0 ; i < mark ; i++ )
	{
		delete container[0];
		container.erase(container.begin());
	}
}

SudokuPopulation::SudokuPopulation(Puzzle &thePuzzle , int theSize)
{
	reproduction = new SudokuOffspring();
	theFit = new SudokuFitness();
	size = theSize;
	factory = new SudokuFactory(*reproduction);
	*initialPuzzle = thePuzzle;
	// Initial member of the population
	container.push_back(&thePuzzle);
	
}

SudokuPopulation::~SudokuPopulation()
{
	delete reproduction;
	delete theFit;
	delete factory;
	// Delete everything in the container that is used to hold the Puzzle
	for ( int i = 0 ; i < container.size() ; i++ )
	{
		delete container[i];
	}
	
}



