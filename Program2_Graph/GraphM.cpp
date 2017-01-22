﻿

#include "graphm.h"
#include <climits>
#include <iomanip>


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

/*
//---------------------------------------------------------------------------
// getPath
// Outputs Dijkstra's path as int values to cout and retrieves the path 
// backwards using recursion and prints in proper order

void GraphM::getPath(const int from, const int to) const
{
	if (from != to)
		if (T[from][to].path != 0)
			getPath(from, T[from][to].path); //Recursive call to find previous

	cout << to << " "; //Print path 
}
*/
//---------------------------------------------------------------------------
// display
// takes two int values and displays source, destination, path, distance, 
// and the names of of of the paths.

void GraphM::display(const int fromNode, const int toNode) const
{
	if (T[fromNode][toNode].dist != INT_MAX) //There is a path
	{
		cout << fromNode << "      " << toNode << "      ";
		cout << T[fromNode][toNode].dist << "        ";
		getPath(fromNode, toNode);
		cout << endl;
	}
	else //Equals Infinity, no path
	{
		cout << left << setw(12) << fromNode << setw(12) << toNode;
		cout << "----        NO PATH";
	}

	getPathData(fromNode, toNode); //Get the Descriptions of path inorder
	cout << endl;
}

//---------------------------------------------------------------------------
// getPathData
// Displays the path data of the two int's passed in.

void GraphM::getPathData(const int from, const int to) const
{
	if (from != to)
		if (T[from][to].path != 0)
			getPathData(from, T[from][to].path); //Recursive call to find previous

	cout << data[T[from][to].path] << endl; //Print path data (description)
}

//---------------------------------------------------------------------------
// displayAll
// Displays Description, From Node, To Node, Dijkstra's, and Path off all 
// the data passed in. Uses "----" for infinity for Dijkstra's

void GraphM::displayAll() const
{
	//Header
	cout << "Description              From Node    To Node    Dijikstra's    ";
	cout << "Path" << endl;

	//Walk through all data and print info
	for (int i = 1;i < size + 1; i++)
	{
		cout << setw(50) << left << data[i] << endl; //50 width for description

		for (int j = 1; j < size + 1; j++)
		{
			if (T[i][j].dist > 0 && T[i][j].dist < INT_MAX)
			{
				cout << setw(31) << right << i << setw(10) << j;
				cout << setw(15) << T[i][j].dist << setw(10);
				getPath(i, j); //Print Path
				cout << endl;
			}
			else
				if (i != j) //No path and no cost
				{
					cout << setw(31) << right << i << setw(10) << j << setw(15);
					cout << "----" << setw(10) << endl;
				}
		}
	}
	cout << endl;
}


void GraphM::insertEdge( int firstNode,  int secondNode,  int weight)
{
		if (firstNode < 1 || firstNode > size || secondNode < 1 || secondNode > size) // Check for valid position
		{
			cout << "Invalid index to use";
			return;
		}
	if (weight < 0 || weight > INT_MAX) // check for valid weight
	{
		cout << "Invalid weight between 2 Node";
		return;
	}
	C[firstNode][secondNode] = weight; //insert cost into specified index
}

void GraphM::removeEdge(int firstNode,  int secondNode)
{
	insertEdge(firstNode, secondNode, INT_MAX);
}

void GraphM::buildGraph(ifstream& file)
{
	int firstNode = 0, 
	int secondNode = 0, 
	int weight= 0;
	string result;
	int size = 0;
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


//---------------------------------------------------------------------------
// findShortestPath
// Performs Dijkstra Shortest Path Algorithm on the current data in C[][]
// adjacency matrix and then puts those values in T[][]. 

void GraphM::findShortestPath()
{
	int v = 0; //v is the current smallest unmarked distance
	int w = 0; //w is current position, used for clarity
	int count = 1;

	for (int source = 1; source <= size; source++) //start at source = 1
	{
		T[source][source].dist = 0; //Set at 0

		while (count != size)
		{
			v = findNext(T[source], 1, size); //find v that is smallest unmarked
			T[source][v].visited = true;    //mark v as visited

			for (int i = 1; i < size + 1; i++)
			{
				w = i; //current position

				if (T[source][w].visited == false && C[v][w] != INT_MAX)
				{
					//Check wether current or going through v is smaller
					if (!(T[source][w].dist < (T[source][v].dist + C[v][w])))
					{
						//Going through v is smaller than current
						T[source][w].dist = (T[source][v].dist + C[v][w]);
						T[source][w].path = v; //Add v to the path
					}
				}
			}
			count++;
		}
		count = 1;
		initArrayVisited();
	}
}

//---------------------------------------------------------------------------
// findNext
// Take three parameters: TableType, int, int. TableType is a 1D array which
// contains current distance value and the tw int are the low and high
// value of the array.

int GraphM::findNext(TableType data[], int low, int hi)
{
	int min = 1; //set at min possible value
	int lowestValue = INT_MAX; //Set at max value

	for (int i = 1;i < size + 1;i++)
	{
		if (data[i].dist < lowestValue && data[i].visited == false)
		{
			min = i;
			lowestValue = data[i].dist;
		}
	}
	return min; //Return v which has shortest dist and is unmarked
}

//---------------------------------------------------------------------------
// initArrayVisited
// Sets false to all visited in all index's in 2D array T[][].

void GraphM::initArrayVisited()
{
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1;j< size + 1;j++)
		{
			T[i][j].visited = false; //set all to false
		}
	}
}