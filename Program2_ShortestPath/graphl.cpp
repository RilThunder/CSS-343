/**
	Assignment 2: Implement Dijkstra's algorith and Depth-first search
	Purpose: Get and process a text file, print out its Depth First Search 
	graphl.cpp Implemtation file

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1.1 January 26th,2017
*/





#include "graphl.h"



GraphL::GraphL()
{
	size = 0;
	for (int i = 1; i < MAX_NODES; i++)
	{
		// Initilize to default value
		// All Graph Node will have NULL value
		data[i].edgeHead = NULL;
		data[i].visited = false;
		data[i].data = NULL;
	}
}


GraphL::~GraphL()
{
	for (int i = 1; i <= size; i++)
	{
		EdgeNode*x = data[i].edgeHead;
		EdgeNode *prev = x;
		while (x != NULL)
		{
			prev = x; // Save the current pointer to delete
			x = x->nextEdge;
			delete prev;
			
		}
		data[i].edgeHead  = NULL;
		data[i].visited = false;
		delete data[i].data;
	}
}

void GraphL::buildGraph(ifstream & file)
{
	int firstNode = 0;
	int secondNode = 0;
	string result = "";
	getline(file, result); // Get how many Node are there in the text file
	if (result == "") 
	{
		return; // Reached the end of file 
	}
	size = stoi(result); // get the first Number
	result = "";
	for (int i = 1; i <= size; i++)
	{
		nodedata* newNode = new nodedata();
		newNode->setData(file);
		data[i].data = newNode;; // Get the data of the Node;
	}
	while (!file.eof())
	{
		getline(file, result);
		stringstream ss(result);
		ss >> firstNode >> secondNode; // Pass in the data
		if (firstNode == 0 && secondNode == 0) // Indicate end of graph
		{
			break;
		}
		insertGraphNode(firstNode, secondNode); //insert line of data
	}
}

void GraphL::displayGraph()
{
	helperOutPut(); 
}

void GraphL::depthFirstSearch()
{
	cout << "Depth First Search : ";
	for (int i = 1; i <= size; i++)
	{
		// Go through everyNode to print out DFS
		helperDFS(i);

	}
	cout << endl;
	return;
}
void GraphL::insertGraphNode(int x, int y)
{
	if (x <= 0 || y <= 0 || x > 100 || y > 100) // Check for special cases
	{
		cout << "Invalid index to use, Can not print out" << endl;
		return;
	}
	EdgeNode* insert = new EdgeNode();
	insert->adjGraphNode = y;
	if (data[x].edgeHead == NULL) // EMpty at the position, need new Node
	{
		insert->nextEdge = NULL; // Set it as the first one
		data[x].edgeHead = insert;
	}
	else
	{
		insert->nextEdge = data[x].edgeHead; // Append the top to the remainder of new Node and make new Node top
		data[x].edgeHead = insert;
	}
	return;
}

void GraphL::helperOutPut()
{
	for (int i = 1; i <= size; i++)
	{
		cout << "Node " << i << "            " << *data[i].data << endl;
		EdgeNode *x = data[i].edgeHead; // Print out the data
		while (x != NULL)
		{
			// Print out its adjancen Node
			cout << "    edge " << i << " " << x->adjGraphNode << endl;
			x = x->nextEdge;
		}
	}

}

void GraphL::helperDFS(int x)
{
	if (data[x].visited)
	{
		return;

	}
	cout << x << " ";
	data[x].visited = true; // Visited this Node. Mark it
	EdgeNode *info = data[x].edgeHead; // Explore the Neighboring Node
	if (info == NULL)
	{
		return;
	}
	int count = info->adjGraphNode;

	while (info != NULL)
	{
		helperDFS(info->adjGraphNode);
		
		info = info->nextEdge;
	}

}


