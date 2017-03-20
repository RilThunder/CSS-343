
/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Population class : Act as the base class for SudokuPopulation.
 * A container for all the Puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#ifndef UNTITLED_POPULATION_H
#define UNTITLED_POPULATION_H


#include "Fitness.h"
#include "PuzzleFactory.h"

class Population
{
public:
	/*
	 * Default constructor for the CSS
	 */
	Population();
	
	
	virtual ~Population();
	
	/*
	 * This function will get the best fitness of the population
	 * @return an integer represeent the best fitness
	 */
	virtual int bestFitness() = 0;
	
	/*
	 * This function will eliminate 90% of the population
	 * This will eliminate the least fit one
	 */
	virtual void naturalSelection() = 0;
	
	/*
	 * This function will get the best individual with the best fitness of the current generation
	 * @return a puzzle that has the best fitness right now
	 */
	virtual Puzzle &bestIndividual()=0;
	
	/*
	 * This function will generate a new generation until the maximum size is met
	 */
	virtual void newGeneration() = 0;

protected:
	
	int size;
	Fitness * theFit;
	PuzzleFactory * factory;
	Reproduction * reproduction;
	vector<Puzzle *> container;
	Puzzle * initialPuzzle;
	
	
};


#endif //UNTITLED_POPULATION_H
