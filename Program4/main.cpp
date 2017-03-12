#include <iostream>
#include "Puzzle.h"
#include "Sudoku.h"
#include "Population.h"
#include "SudokuPopulation.h"

using namespace std;

int main(int argc , char * argv[])
{
	// First argument is size, second is number of iteration
	Puzzle * a = new Sudoku();
	cin >> *a;
	cout << endl;
	cout << "Original Puzzle : " << endl;
	cout << *a;
	cout << endl;
	
	
	Population * x;
	
	x = new SudokuPopulation(*a , atoi(argv[1]));
	int min = x->bestFitness();
	// Generate the initial Puzzle;
	x->newGeneration();
	
	// This is used to capture the best fitness that we encountered
	int bestSoFar = INT32_MAX;
	Puzzle * best;
	for ( int i = 0 ; i < atoi(argv[2]) ; i++ )
	{
		if ( x->bestFitness() == 0 )
		{
			// Found a solution
			*best = x->bestIndividual();
			cout << *best;
			
			break;
		}
		x->naturalSelection();
		
		
		x->newGeneration();
		
		
		if ( x->bestFitness() < bestSoFar )
		{
			bestSoFar = x->bestFitness();
		}
		
		
	}
	cout << "Original fitness of the Puzzle : ";
	cout << min << endl;
	
	cout << "The result fitness of the Puzzle: " << endl;
	cout << x->bestIndividual();
	cout << endl;
	cout << "The result fitness of the Puzzle: ";
	cout << x->bestFitness();
	cout << endl;
	
	cout << "The best fitness the we have encountered: ";
	cout << bestSoFar;
	cout << endl;
	
	delete x;
}