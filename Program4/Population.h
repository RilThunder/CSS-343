//
// Created by thuan on 09/03/17.
//

#ifndef UNTITLED_POPULATION_H
#define UNTITLED_POPULATION_H


#include "Fitness.h"
#include "PuzzleFactory.h"

class Population
{
public:
	Population(Fitness &theFit , Reproduction &reproduction , Puzzle &initialPuzzle , PuzzleFactory &theFactory ,
	           int theSize);
	
	virtual int bestFitness();
	
	virtual Puzzle &bestIndividual();
	
	virtual void newGeneration();

protected:
	int size;
	Fitness * theFit;
	PuzzleFactory * factory;
	Reproduction * reproduction;
	vector<Puzzle> container;
	Puzzle * initialPuzzle;
	
	
};


#endif //UNTITLED_POPULATION_H
