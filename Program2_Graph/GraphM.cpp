

#include "graphm.h"


GraphM::GraphM()

{
	// Initialize all Node to have Maximum weight and distance
	for (int i = 1; i < MAXNODES; i++) 
	{
		for (int j = 1; j < MAXNODES; j++)
		{
			T[i][j].dist = INT_MAX;
			T[i][j].visited = false;
			T[i][j].path = 0;
			C[i][j] = INT_MAX;
		}
	}
	size = 0;
}

GraphM::~GraphM()
{
}

void GraphM::getNumberPath(int startNode, int endNode) 
{
	// Recursively get the path
	// To get from 1 to 4, we need from 1-3, to get from 1-3, we need from 1-2 and etc..
	// Work backward
	if (startNode != endNode)
	{
		if (T[startNode][endNode].path != 0) // Check if we can get to that Node 
		{
			getNumberPath(startNode, T[startNode][endNode].path); 
		}
	}
	cout << endNode << " "; 
}

//---------------------------------------------------------------------------
// display
// takes two int values and displays source, destination, path, distance, 
// and the names of of of the paths.

void GraphM::display( int startNode,  int endNode) 
{
	cout << endl; 
	if (startNode <= 0 || endNode <= 0 || startNode > 100 || endNode > 100)
	{
		cout << "Invalid index to use, Can not print out" << endl;

	}
	if (T[startNode][endNode].dist != INT_MAX) // Check to see if we can reach from 2 Node;
	{
		cout << startNode  << setw(20)<< endNode ;
		cout << setw(20) <<T[startNode][endNode].dist << setw(20);
		getNumberPath(startNode, endNode); // Print out the numeric distance
		cout << endl;
	}
	else //Equals Infinity, no path
	{
		cout <<  startNode << setw(20) << endNode ;
		cout << setw(20 ) << " Unreachable" ;
		cout << endl;
		return;
	}

	getStringPath(startNode, endNode); //Get the Descriptions of path before desitionation 
	cout << data[endNode]; // Print out the destination 
	cout << endl;
}


void GraphM::getStringPath( int startNode,  int endNode) 
{
	// Recursively get the path
	
	if (startNode != endNode)
	{
		if (T[startNode][endNode].path != 0)  // Check if we can ever reach the destination from the starting point
		{
			getStringPath(startNode, T[startNode][endNode].path);
		}
	}
	cout << data[(T[startNode][endNode].path)] << endl;  // Print out the previous path
}



void GraphM::displayAll()
{
	cout << endl;
cout << "Description     "   << "From Node    "  << "To Node    " <<    "Dijikstra's  ";
cout <<  "Path" << endl;

// loop through the table and print out 
for (int i = 1;i <= size ; i++)
{
	cout <<  data[i] << endl; 
	// Skip a line to print out the path
	for (int j = 1; j <= size; j++)
	{
		if (i == j)
		{
			continue; // Do not need to print itself
		}
		if (T[i][j].dist > 0 && T[i][j].dist < INT_MAX)
		{
			cout  << setw(20) <<i   << setw(11) << j << " ";
			cout <<  setw(10) << T[i][j].dist << setw(13) ;
			getNumberPath(i, j); //Print Path
			cout << endl;
		}
		else
			{
				cout  <<setw(20) <<i << setw(10) << j;
				cout << setw(15) << "-----" << endl;
			}
	}
}
      
}


void GraphM::insertEdge(int firstNode, int secondNode, int weight)
{

	if (weight < 0 || weight > INT_MAX) // check for valid weight
	{
		cout << "Invalid weight between 2 Node";
		return;
	}
	C[firstNode][secondNode] = weight; //insert cost into specified index
}

void GraphM::removeEdge(int firstNode, int secondNode)
{
	insertEdge(firstNode, secondNode, INT_MAX);
}

void GraphM::buildGraph(ifstream& file)
{
	int firstNode = 0;
		int secondNode = 0;
		int weight = 0;
	string result;
	
	size = file.get() - '0';
	getline(file, result);
	for (int i = 1; i <= size; i++)
	{
		data[i].setData(file); // Get the data of the Node;
	}
	while (!file.eof())
	{
		getline(file, result);
		stringstream ss(result);
		ss >> firstNode >> secondNode >> weight;
		if (firstNode == 0 && secondNode == 0 && weight == 0) // Indicate end of graph
		{
			break;
		}
		insertEdge(firstNode, secondNode, weight); //insert line of data
	}
}




void GraphM::findShortestPath()
{
	int v = 0;  // Minimum Node that has not been marked
	for (int source = 1; source <= size; source++)
	{
		T[source][source].dist = 0; //Set the initial distance to 0

		for (int j = 1; j <= size; j++)
		{
			v = minimumDistance(source); //find v that is smallest unmarked
			T[source][v].visited = true;    //mark v as visited

			for (int i = 1; i <= size; i++)
			{
				if ((T[source][i].visited) || (C[v][i] == INT_MAX  )  )
				{
				  continue; // Skip the vertex where we visited or where we can not reach

                }

					if ((T[source][i].dist > (T[source][v].dist + C[v][i])))
					{
						T[source][i].dist = T[source][v].dist + C[v][i];
						T[source][i].path = v; //Add v to the path
					}
				}
			}
			
		}
		
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1;j< size + 1;j++)
		{
			T[i][j].visited = false; //set all to false
		}
	}
	}




int GraphM::minimumDistance(int x)
{
	int min = INT_MAX;
	int result = 1;

	for (int i = 1;i < size + 1;i++)
	{
		if (T[x][i].visited)
		{
			continue;
		}
		if (T[x][i].dist < min) // Find a new minimum distance
		{
			 min = T[x][i].dist;
			 result = i;
		}
	}
	return result; //Return v which has shortest dist and is unmarked
}

