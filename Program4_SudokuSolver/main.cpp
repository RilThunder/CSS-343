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
//	x = new SudokuPopulation(*a , 20);
	int min = x->bestFitness();
	// Generate the initial Puzzle;
	x->newGeneration();
	int resultIteration = 0;
	// This is used to capture the best fitness that we encountered
	int bestSoFar = INT32_MAX;
	bool flag = false;
	Puzzle * best;
	for ( int i = 1 ; i <= atoi(argv[2]) ; i++ )
		//for ( int i = 0 ; i < 100 ; i++ )
	{
		if ( x->bestFitness() == 0 )
		{
			// Found a solution
			flag = true;
			resultIteration = i;
			Puzzle * result = &x->bestIndividual();
			best = result;
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
	
	if ( flag )
	{
		cout << "The solution of the sudoku is ";
		cout << endl;
		
		cout << *best;
		cout << endl;
		cout << "The result was found at the " << resultIteration << "th iteration" << endl;
		
	} else
	{
		cout << "A solution was not found in this iteration" << endl;
		cout << "The result fitness of the Puzzle: " << endl;
		cout << x->bestIndividual();
		cout << endl;
		cout << "The result fitness of the Puzzle: ";
		cout << x->bestFitness();
		cout << endl;
		
		cout << "The best fitness the we have encountered: ";
		cout << bestSoFar;
		cout << endl;
	}
	delete x;
}