
/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of SudokuPopulation class : A container for all the Sudoku
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */
#ifndef UNTITLED_SUDOKUPOPULATION_H
#define UNTITLED_SUDOKUPOPULATION_H


#include "Population.h"

class SudokuPopulation : public Population
{
public:
	/*
	 * This is the destructor for the SudokuPopulation
	 */
	virtual ~SudokuPopulation();
	
	/*
	 * This is the constructor for the Sudoku Population
	 * @param initialPuzzle this is the seed that will generate
	 * @param theSize Size of the population
	 */
	SudokuPopulation(Puzzle &initialPuzzle , int theSize);
	
	/*
	 * Get the best fitness of the population
	 */
	int bestFitness();
	
	/*
	 * Eleminate 90% of the population
	 */
	void naturalSelection();
	
	/*
	 * Return the best individual at the current generation of the population
	 */
	Puzzle &bestIndividual();
	
	/*
	 * Generate a new generation based on what is left
	 */
	void newGeneration();
	
	
};


#endif //UNTITLED_SUDOKUPOPULATION_H
