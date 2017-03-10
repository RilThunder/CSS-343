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
	Population();
	
	
	virtual ~Population();
	
	virtual int bestFitness() = 0;
	
	virtual void naturalSelection() = 0;
	
	virtual Puzzle &bestIndividual()=0;
	
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
