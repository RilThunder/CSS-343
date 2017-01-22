/**
	Assignment 2: Implement Dijkstra's algorith and Depth-first search
	Purpose: Get and process a text file, print out its path
	GraphM.h Header File 

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1.1 January 22th,2017
*/

#ifndef _GRAPHM_H
#define _GRAPHM_H
#include "nodedata.h"
#include <climits>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


class GraphM
{
public:
	/**
		This is the constructor for the GraphM class
		The constructor will initlize everything to default
		The cost matrix will be infinity
		the data member T is initialized to sets all dist to infinity, sets all visited to false, and sets all path to 0.
	*/
	GraphM();

	/**
		This is the default constructor
		Not implemented
	*/
	~GraphM();

	/**
		This function will take in a text file and construct a new graph out of it
		@param file the text file
	*/
	void buildGraph(ifstream& file);
	
	/**
		This function will insert a new edge into the Graph
		It will only create 1 direction from first Node to second Node but not vice versa
		@param firstNode the firstNode to insert
		@param secondNode the second Node to insert
		@param weight the weight between 2 node
	*/
	void insertEdge(int firstNode, int secondNode, int weight);

	/**
		This function is used to find the Shortest path from every node to every other node
	*/
	void findShortestPath(); 

	/**
		This function can be used to display all the shortest path from every node to every other node
	*/
	void displayAll();

	/**
		This function can be used to diplay more detail from a particular node to other node
		@param startNode the starting point
		@param endNode the destination
	*/
	void display(int startNode, int endNode);
	
	/**
		This function can be used to delete an edge between 2 node
		This will remove edge from firstNode to secondNode but not vice versa
		@param firstNode the start Node
		@param secondNode the end Node
	*/
	void removeEdge(int firstNode, int secondNode); 

private:
	static const int MAXNODES = 101; // A maximum 100 Nodes per graph. This is used to start index at 1
	struct TableType
	{
		bool visited; // If this location has been visited
		int dist; // shortest distance from source known so far
		int path; // previous node in path of min dist
	};
	NodeData data[MAXNODES]; // data for graph nodes information
	int C[MAXNODES][MAXNODES]; // Cost array, the adjacency matrix
	int size; // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES]; // stores visited, distance, path
	
	/**
		This helper method is used to print out the numeric path from one node to other node
		@param startNode the starting Node
		@param endNode the destination Node
	*/
	void getNumberPath(int startNode, int endNode); 

	/**
		This helper method is used to print out the string description from one node to other node
		@param startNode the starting Node
		@param endNode the destination Node
	*/
	void getStringPath(int startNode, int endNode); 

	/**
		This helper method is used to return the index of the minimum neighbor Node from the source
		@param source the Source
		@return an integer represent the index of smallest neighbor Node 
	*/
	int minimumDistance(int source);
};
#endif