//
// Created by thuan on 09/03/17.
//

#ifndef UNTITLED_SUDOKUPOPULATION_H
#define UNTITLED_SUDOKUPOPULATION_H


#include "Population.h"

class SudokuPopulation : public Population
{
public:
	SudokuPopulation(Fitness &theFit , Reproduction &reproduction , Puzzle &initialPuzzle , PuzzleFactory &theFactory ,
	                 int theSize);
	
	SudokuPopulation(Puzzle &initialPuzzle , int theSize);
	int bestFitness();
	
	void naturalSelection();
	
	Puzzle &bestIndividual();
	
	void newGeneration();
};


#endif //UNTITLED_SUDOKUPOPULATION_H
