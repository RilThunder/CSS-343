/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of SudokuFitness class : Asset the fitness of a Sudoku
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */
#ifndef UNTITLED_SUDOKUFITNESS_H
#define UNTITLED_SUDOKUFITNESS_H


#include <vector>
#include "Fitness.h"

class SudokuFitness : public Fitness
{
public:
	/*
	 * This function will be used to asset the fitness of a Puzzle (Sudoku really)
	 * @param thePuzzle reference to the Puzzle(Sudoku)
	 * @return an integer represent the fitness of the Puzzle
	 */
	int howFit(Puzzle &thePuzzle);
	
	/*
	 * Default constructor
	 */
	SudokuFitness();

private:
	/*
	 * This helper function will be used to asset the fitness of a Puzzle
	 * @param x the representation of the Sudoku
	 * @return an integer represent the fitness of the Sudoku
	 */
	int howFit(vector<vector<int>> &x);
	
};


#endif //UNTITLED_SUDOKUFITNESS_H
