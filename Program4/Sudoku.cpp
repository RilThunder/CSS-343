/*
 * Program 4: Implement a Genetic Algorithm Solver for Sudoku Puzzle
 * Purpose of Sudoku class : A sudoku puzzle
 * @author Thuan Tran, CSSE Junior at the University of Washington Bothell
 * March 11th, 2017
 * @version 1.1
 */

#include "Sudoku.h"

Sudoku::Sudoku()
{
	for (int i = 0 ; i < 9; i++)
	{
		for (int j =0; j<9; j++)
		{
			// Initialize default variable
			Entry defaultEntry = Entry();
			defaultEntry.value=0;
			defaultEntry.isValue = false;
			representation[i][j]= defaultEntry;
		}
	}
}

void Sudoku::helpOutput(ostream &output) const
{
	output << " +--------+--------+--------+" << endl;
	for ( int i = 1 ; i <= 9 ; i++ )
	{
		output << " | ";
		// use this numbering system to make it easier to do modoulus
		for ( int column = 1 ; column <= 9 ; column++ )
		{
			output << representation[i - 1][column - 1].value;
			output << " ";
			// 3 number already, time to separate them
			if ( column % 3 == 0 )
			{
				output << " | ";
			}
			
		}
		output << endl;
		// 3 row already, time to print out seperator
		if ( i % 3 == 0 )
		{
			output << " +--------+--------+--------+";
			output << endl;
		}
		
	}
	
}

void Sudoku::helpInput(istream &input)
{
	// Assume that the textfile is one line
	cout << "Enter the File Name: ";
	string fileName;
	cin >> fileName;
	int count = 0;
	int row = 0;
	int column = 0;
	string line = "";
	ifstream myFile(fileName.c_str());
	if ( myFile.is_open())
	{
		while ( !myFile.eof())
		{
			// loop through each line of the file
			getline(myFile , line);
			for ( char x : line )
			{
				if ( isdigit(x))
				{
					// Identify which one
					Entry newEntry = Entry();
					newEntry.value = x - '0';
					newEntry.isValue = newEntry.value != 0;
					representation[row][column] = newEntry;
					
					column++;
					count++;
				}
			}
			column = 0; //start again at new row
			row++;
		}
		// The text file does not have enough data to create the sudoku
		if ( count != 81 )
		{
			cout << "Not enough to create the puzzle";
			
		}
		myFile.close();
	} else
	{
		cout << "Unable to open file";
	}
	
}

vector<vector<int>> Sudoku::getSudoku()
{
	vector<vector<int>> x(9 , vector<int>(9));
	// copy the value over
	for ( int i = 0 ; i < 9 ; i++ )
	{
		for ( int j = 0 ; j < 9 ; j++ )
		{
			x[i][j] = representation[i][j].value;
		}
	}
	return x;
	
}

void Sudoku::insert(int value , bool isValue , int row , int column)
{
	if ( (value < 0 ) || (value > 9) || (row <0) || (row >8) || (column <0) || (column >8))
	{
		cout << "Invalid input arguments";
	}
	representation[row][column].value = value;
	representation[row][column].isValue = isValue;
	return;
}

bool Sudoku::isValue(int row , int column)
{
	// is this a fixed value ?
	return representation[row][column].isValue;
}


