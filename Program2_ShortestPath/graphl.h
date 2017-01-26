#ifndef _GRAPHL_H
#define _GRAPHL_H
#include "nodedata.h"
#include <climits>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#pragma once
class graphl
{
public:
	graphl();
	~graphl();

	/**
	This function will take in a text file and construct a new graph out of it
	@param file the text file
	*/
	void buildGraph(ifstream& file);


	/**
	This fuction can be used to display the info of the graph
	*/
	void displayGraph();

	/**
	This function will be used to show the depth first search order of the graph
	*/
	void depthFirstSearch();



private:
	static const int MAX_NODES = 101;

	struct EdgeNode;      // forward reference for the compiler 
	struct GraphNode
	{    // structs used for simplicity, use classes if desired 
		EdgeNode* edgeHead; // head of the list of edges 
		nodedata* data;     // data information about each node
		bool visited;

	};
	struct EdgeNode
	{
		int adjGraphNode;  // subscript of the adjacent graph node 
		EdgeNode* nextEdge;
	};
	GraphNode data[MAX_NODES];


	int size; // How many Nodes are there in the graph

	void insertGraphNode(int x, int y);

	void helperOutPut();

	void helperDFS(int x);


};
#endif
