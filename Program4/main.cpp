#include <iostream>
#include "Puzzle.h"
#include "Sudoku.h"
#include "Fitness.h"
#include "SudokuFitness.h"

using namespace std;

int main()
{
	Puzzle * a = new Sudoku();
	cin >> *a;
	cout << *a;
	Fitness * fit = new SudokuFitness();
	cout << fit->howFit(*a);
	delete fit;
}