/**
	Assignment 1: Word Counting using a Binary Search Tree
	CountWords.cpp
	Purpose: Get and process a text file, print out its content and frequency

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1.1 January 10th,2017
*/

#include <iostream>
#include <string>
#include "WordTree.h"
#include <ctype.h>
#include <fstream>
using namespace std;



void processString(string theString, WordTree &tree) {}


/**
	This main module will allow the user to enter the name of the text file and print out the content
	REQUIREMENT: The text file must in be the same local directory
*/
int main()
{
	string filename = "";
	cout << "Please input the file name (with .txt extension): ";
	cin >> filename;
	WordTree *theTree = new WordTree();
	string line = "";
	ifstream myfile (filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line)) // Process until the end of file
		{
			if (line.empty()) // Skip over empty line

			{
				continue;
			}
			processString(line, *theTree);
		}
		myfile.close(); // Close the file when done
	}

	else
	{
		cout << "Unable to open file";
	}
	// Dereferene the WordTree and print out it content in alphabetical order
	cout << *theTree;
	return 0;


}


/**
	This method will be used to process each line in the text file and add to the WordTree
	@param theString the line in the text file
	@param tree Reference to the WordTree in main module
*/
void processString(string theString, WordTree &tree)
{
	string result = "";
	bool number = false;
	for (char a : theString)
	{
		if (!number) // No number in between
		{
			if (isalpha(a) || a == '\'') 
			{
				result += (char)tolower(a); // Ignore capitalization
			}
			else
			{
				if (isspace(a) && !result.empty()) // Reached a space , time to add to the tree
				{
					tree.Add(result);
					result = "";
					continue;
				}
				// A number is in between, do not add and reset
				number = true;
				result = "";
			}
		}
		else
		{
			// There has been a number but we reached a space, time to start over
			if (isspace(a))
			{
				number = false;
			}
			// Continue to scan until reach a space to start over
			else
			{
				continue;
			}
		}
	}
}