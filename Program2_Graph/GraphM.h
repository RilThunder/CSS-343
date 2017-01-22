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
	GraphM();
	~GraphM();
	void buildGraph(ifstream& file);
	
	void insertEdge(int firstNode, int secondNode, int weight);
	void findShortestPath(); 
	void displayAll();
	void display(int startNode, int endNode);
	
	
	void removeEdge(int firstNode, int secondNode); 




private:
	static const int MAXNODES = 101; //101 since index 0 is not used
	struct TableType
	{
		bool visited; // whether node has been visited
		int dist; // shortest distance from source known so far
		int path; // previous node in path of min dist
	};
	NodeData data[MAXNODES]; // data for graph nodes information
	int C[MAXNODES][MAXNODES]; // Cost array, the adjacency matrix
	int size; // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES]; // stores visited, distance, path
	



	void getNumberPath(int startNode, int endNode); //Print path from/to node
	void getStringPath(int startNode, int endNode); //Print description's 
	int minimumDistance(int source);
};
#endif