Part 1: Programming (Dijkstra's shortest path algorithm) 

 

In this assignment you will implement Dijkstra's shortest path algorithm. Your code should be able to: 

    Read a data file consisting of many lines (see example file data31.txt)  

    Find the lowest cost paths (through the findShortestPath function)  

    Display the cost and path from every node to every other node (thought he displayAll function).  Another display routine (display    function) should output one path in detail.  

  

In the input data (e.g., data31.txt), the first line tells the number of nodes n, followed by a text description of each of the nodes (from 1 to n), and one description per line (50 chars max length).  After that, each line consists of 3 integers representing an edge in a graph. If there is an edge from node 1 to node 2 with a label of 10, the data is: 1 2 10. Three zeroes in a row (the first three integers) signify the end of the data for that one graph Note that there may be several graphs in a file, each having at most 100 nodes.   

 

For example, Figure 1 (a) shows part of data from data31.txt containing 5 nodes.  For clarity and as reference, Figure 1(b) shows a graph drawn based on data (you do not need to implement or output this graph, neither it is part of the input data). 

![ScreenShot](https://github.com/RilThunder/CSS-343/blob/master/Program2_ShortestPath/image.png)
 

You can assume for both parts of this lab, that the input data file has correctly formatted, valid data. 





Implement the following class 

 

1. Class attributes include an array of NodeData (NodeData.h and NodeData.cpp will be given), the adjacency matrix, number of nodes, and TableType array.   

  

class GraphM {                             

   public: 

      ... 

   private: 

      NodeData data[MAXNODES];              // data for graph nodes  

      int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix 

      int size;                             // number of nodes in the graph 

      TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path 

   }; 

  

TableType is a struct that keeps the current shortest distance (and associated path info) known at any point in the algorithm. 

  

  struct TableType { 

         bool visited;          // whether node has been visited 

         int dist;              // shortest distance from source known so far 

         int path;              // previous node in path of min dist 

      }; 

  

T is a 2-dimensional array of structs to allow work from all nodes to all other nodes.  

  

 

2. The pseudocode given in class is for a single source node (node 1 was used).  In order to check all nodes with respect to all other nodes, you can use the following pseudo for your implementation: 

  

for (int source = 1; source <= nodeSize; source++) { 

      T[source][source].dist = 0; 

  

      // finds the shortest distance from source to all other nodes 

      for (int i = 1; i<= nodeSize; i++) { 

         find v //not visited, shortest distance at this point 

         mark v visited   

         for each w adjacent to v 

           if (w is not visited) 

            T[source][w].dist=min(T[source][w].dist, T[source][v].dist+C[V][W])  

      } 

   } 

Note:  in T, index 0 is not used. This is to match with the node numbering style. Also this pseudocode is only for keeping the shortest distance, you will need to design and implement a way to record associated path info. 

 

  

3. You do not need to implement a complete Graph class. The only methods you should have are 

    constructor: among others that need to be initialized, the data member T is initialized to sets all dist to infinity, sets all visited to false, and sets all path to 0. 

    buildGraph: builds graph node information and adjacency matrix of edges between each node based on the information from a data file. 

    insertEdge: insert an edge into graph between two given nodes 

    removeEdge: remove an edge between two given nodes 

    findShortestPath: find the shortest path between every node to every other node in the graph, i.e., TableType T is updated with shortest path information 

    displayAll: uses cout to demonstrate that the algorithm works properly. For the data in Figure 1, it will produce the sample output below (use a similar format -- spaces do not need to be exactly the same): 

  

Description               From node  To node  Dijkstra's  Path     

Aurora and 85th 

                               1       2      40          1 3 2   

                               1       3      20          1 3      

                               1       4      50          1 3 2 4 

                               1       5      30          1 5  

  

Green Lake Starbucks 

                               2       1      ---  

                               2       3      ---  

                               2       4      10          2 4   

                               2       5      --- 

  

Woodland Park Zoo 

                               3       1      ---  

                               3       2      20          3 2     

                               3       4      30          3 2 4  

                               3       5      ---  

  

Troll under bridge 

                               4       1      ---  

                               4       2      --- 

                               4       3      ---  

                               4       5      ---  

  

PCC 

                               5       1      ---  

                               5       2      20          5 2 

                               5       3      ---  

                               5       4      25          5 4 

  

    display: uses cout to display the shortest distance with path info between the fromNode to toNode.  For the data in Figure 1, a call of G.display(1,4) is going to produce the following output (similar to):  

  

   1       4      50          1 3 2 4 

Aurora and 85th 

Woodland Park Zoo 

Green Lake Starbucks 

Troll under Aurora bridge 

  

 

    Some utility functions may be needed. 

  

 

List of supporting files  

A zip containing these files can be downloaded from this link  Canvas->Files->assignments->Program2 

    data31.txt: input data file; 

    nodedata.h and nodedata.cpp: NodeData class; 

    lab3.cpp: containing main(), to help clarify the functional requirements; NOTE: this is used for part 2 too, so comment out things related to part 2 when you are focusing on part 1. 

    lab3output.txt: correct output in using lab3.cpp; NOTE: this includes results from part 2 too. 

    dataUWB.txt: an additional data set for part 1, no correct output will be provided.  

  

 

Submission Requirements: 

All the rules, submission requirements, and evaluation criteria are the same as the assignment 2. 
