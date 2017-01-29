/**
	Assignment 2: Implement Dijkstra's algorith and Depth-first search
	Purpose: Get and process a text file, print out its path
	Graphl.h Implemtation file

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1.1 January 22th,2017
*/




#ifndef _GRAPHL_H
#define _GRAPHL_H
#include "nodedata.h"
#include <climits>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#pragma once
class GraphL
{
public:
	/**
		This will be the default constructor for this Depth First Search Graph
		It will initialize all value to default value
	
	*/
	GraphL();

	/**
		This is the destructor for this Depth First Search Graph
		
	*/
	~GraphL();

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

	/**
		This function will be use to insert into the Graph
		@param x The location of the item where it will be inserted

		@param y The location of its adjacent Node
	
	*/
	void insertGraphNode(int x, int y);

	/**
		This is the private helper method to print out the Node information
		
	*/
	void helperOutPut();


	/**
		This is the private helper method to print out the Depth First Search
		@param x the location of the Node we are at
	*/
	void helperDFS(int x);


};
#endif
