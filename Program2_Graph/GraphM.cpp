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
		firstNode = newLine.at(0) -1; // To match the the index of an array
		lastNode = newLine.at(2) -1;
		weight = newLine.at(4);
		if ((firstNode == lastNode ) && (lastNode== weight))
		{

			endOfGraph = true;
			break;
		}
		C[firstNode][lastNode] = weight; // Do not need to worry about other location since I'll take care of it at the constructor;

	}
	return;
	
}

void GraphM::insertEdge(int firstNode, int secondNode, int weight)
{
}

void GraphM::removeEdge(int firstNode, int secondNode)
{
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
