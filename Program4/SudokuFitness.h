//
// Created by thuan on 03/03/17.
//

#ifndef UNTITLED_SUDOKUFITNESS_H
#define UNTITLED_SUDOKUFITNESS_H


#include <vector>
#include "Fitness.h"

class SudokuFitness : public Fitness
{
public:
	int howFit(Puzzle &thePuzzle);
	
	SudokuFitness();

private:
	int howFit(vector<vector<int>> &x);
	
};


#endif //UNTITLED_SUDOKUFITNESS_H
