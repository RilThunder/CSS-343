//
// Created by thuan on 01/03/17.
//

#include "Sudoku.h"

Sudoku::Sudoku()
{

}

void Sudoku::helpOutput(ostream &output) const
{

}

void Sudoku::helpInput(istream &input)
{
	string fileName;
	cin >> fileName;
	
}

/*
istream & operator>>(istream &input , ifstream &theFile)
{
	int count = 0;
	int row=0;
	int column = 0;
	string line = "";
	while (!theFile.eof())
	{
		getline(theFile,line);
		for (char x : line)
		{
			if (isdigit(x))
			{
				 input = new Entry();
				input->value =
				
			}
		}
	}
	
}

*/
