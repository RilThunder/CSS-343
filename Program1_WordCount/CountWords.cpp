/**




*/
#include <iostream>
#include <string>
#include "WordTree.h"
#include <ctype.h>
using namespace std;



int main()
{


}



void processString(string theString, WordTree &tree)
{
	string result = "";
	bool number = false;
	for (char a : theString)
	{
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
		result = result + (char)tolower(a);
		
	

	}



}