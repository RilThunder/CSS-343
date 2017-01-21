/**
	Assignment 2: Using Dijkstra's Algorithm to find the shortest path
	Create a Graph class that can will be able to display path from a text file 
	GraphM.h
	Purpose: Headerfile for the GraphM.cpp

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1.1 January 20th,2017
*/






#ifndef _GRAPH_H
#define _GRAPH_H
#include "NodeData.h"
#include <iostream>
#include<string>
#include <limits>
using namespace std;

#pragma once

class GraphM
{




public:
	
	GraphM();
	~GraphM();
	void buildGraph(ifstream &file);
	void insertEdge(int firstNode, int secondNode, int weight);
	void removeEdge(int firstNode, int secondNode);
	void findShortestPath();
	void displayAll();
	void display(int startNode, int endNode);

private:
    struct TableType
	{
		bool visited;          // whether node has been visited 
		int dist;              // shortest distance from source known so far 
		int previousVertex;              // previous node in path of min dist 
	};
	static const int MAXNODES = 100;
	NodeData data[MAXNODES];              // data for graph nodes  
	int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix 
	int size;                             // number of nodes in the graph 
	TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path 





};

#endif 