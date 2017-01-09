/**




*/
#include <iostream>
#include <string>
#include "WordTree.h"
#include <ctype.h>
#include <fstream>
using namespace std;



void processString(string theString, WordTree &tree);

int main()
{
	WordTree *theTree = new WordTree();
	string line = "";
	ifstream myfile ("text.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (line.empty())

			{
				continue;
			}
			processString(line, *theTree);
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}
	cout << *theTree;

	return 0;


}



void processString(string theString, WordTree &tree)
{
	string result = "";
	bool number = false;
	for (char a : theString)
	{
		if (!number)
		{
			if (isalpha(a) || a == '\'')
			{
				result += (char)tolower(a); // Ignore capitalization
			}
			else
			{
				if (isspace(a) && !result.empty())
				{
					tree.Add(result);
					result = "";
					continue;
				}
				number = true;
				result = "";

			}

		}
		else
		{
			if (isspace(a))
			{
				number = false;
			}
			else
			{
				continue;
			}
		}



	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

		/*
		if (isspace(a) )
		{	
			for (char b : result)
			{

				if ( ! (isalpha(b) || b == '\'') ) // If not alphabet or ' character, then invalid 
				{
					result = ""; // Check for digit before adding to tree
					break;
				}
			}

			if (result == "")
			{
				continue;
			}
			tree.Add(result);
			result = "";
		}
		result = result + (char)tolower(a);*/
		
	

	



}