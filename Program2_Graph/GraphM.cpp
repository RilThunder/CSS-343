#include "GraphM.h"



GraphM::GraphM()
{
	for (int i = 0 ; i<MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES;j++)
		{
			C[i][j] = INT_MAX;
			TableType x = T[i][j];
			x.dist = INT_MAX;
			x.previousVertex = 0;
			x.visited = false;

		}
	}
	
	
}


GraphM::~GraphM()
{
}

void GraphM::buildGraph(ifstream & file)
{
	bool flag = true;
	int x = file.get();
	for (int i = 0; i < x; i++)
	{
		NodeData newNode;
		newNode.setData(file); 
		data[i] = newNode; // Becareful of the index of Node in the textfile
		size++;
	}
	bool endOfGraph = false;
	int firstNode;
	int lastNode;
	int weight;
	while (!endOfGraph)
	{
		string newLine;
		getline(file, newLine);
		firstNode = newLine.at(0) ; // To match the the index of an array
		lastNode = newLine.at(2) ;
		weight = newLine.at(4);
		if ((firstNode == lastNode ) && (lastNode== weight))
		{

			endOfGraph = true;
			break;
		}
		insertEdge(firstNode, lastNode, weight);// Do not need to worry about other location since I'll take care of it at the constructor;

	}
	return;
	
}

void GraphM::insertEdge(int firstNode, int secondNode, int weight)
{
	if ((firstNode > 100) || (secondNode > 100) || (firstNode < 0) || (secondNode < 0) || (weight < 0))
	{
		return;
	}
	C[firstNode - 1][secondNode - 1] = weight;
}

void GraphM::removeEdge(int firstNode, int secondNode)
{
	insertEdge(firstNode, secondNode, INT_MAX); // instead of deleting, set the weight to be max

}

void GraphM::findShortestPath()
{
}



void GraphM::displayAll()
{
}

void GraphM::display(int startNode, int endNode)
{
}
//
/*for (int i = 1; i <= nodeSize; i++)
{

	Initialize all vertices v as unvisited, with Dv=∞, except for the source, which has Ds=0.
	Repeat n – 1 times:
		Let v be the unvisited vertex with the minimum known distance from the source.
		Mark v as visited.
		For each unvisited vertex w that is adjacent to v:
			If (Dw > Dv + dv,w):
				Set Dw = Dv + dv,w
				Remember that you go through v to get to w.


	int source = 0;
	int v = 0;
	T[v][v].dist = 0; 
	int min = INT_MAX;
	for (int i = 1 ; i < size; i++)
	{
		if (T[v][i].visited)
		{
			continue;
		}

		if (C[v][i] < min) // Comparing the cost between function 
		{
			min = C[v][i];
			v= i ;
		}
	}
	if (v == 0)
	{
		// No other node connected to this one 
		break;
	}
	v.visited = true; 
	for (int i = 1 ; i < size; i++)
	{
		if ( T[v][i].visited)
		{
			continue;
		}
		if T[source][i] > T[source][v] + C[v][i]
		{

		T[source][i] = T[source][v] + C[v][i
		T[source][i].path = v;
		}

		

	}
				
				
				
				
				*/




