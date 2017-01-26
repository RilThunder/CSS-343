#include "graphl.h"



graphl::graphl()
{
	size = 0;
	for (int i = 1; i < MAX_NODES; i++)
	{
		// All Graph Node will have NULL value
		data[i].edgeHead = NULL;
		data[i].visited = false;
		data[i].data = NULL;
	}
}


graphl::~graphl()
{
}

void graphl::buildGraph(ifstream & file)
{
	int firstNode = 0;
	int secondNode = 0;
	string result;
	size = file.get() - '0'; // get the first Number
	getline(file, result);// skip that number
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

void graphl::displayGraph()
{
	helperOutPut();
}

void graphl::depthFirstSearch()
{
	cout << "Depth First Search : ";
	for (int i = 1; i <= size; i++)
	{
		helperDFS(i);

	}
	cout << endl;
	return;
}
void graphl::insertGraphNode(int x, int y)
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

void graphl::helperOutPut()
{
	for (int i = 1; i <= size; i++)
	{
		cout << "Node " << i << "            " << *data[i].data << endl;
		EdgeNode *x = data[i].edgeHead;
		while (x != NULL)
		{

			cout << "    edge " << i << " " << x->adjGraphNode << endl;
			x = x->nextEdge;
		}
	}

}

void graphl::helperDFS(int x)
{
	if (data[x].visited)
	{
		return;

	}
	cout << x << " ";
	data[x].visited = true;
	EdgeNode *info = data[x].edgeHead;
	if (info == NULL)
	{
		return;
	}
	int count = info->adjGraphNode;

	while (info != NULL)
	{
		helperDFS(info->adjGraphNode);
		//data[count].visited = true;
		info = info->nextEdge;
	}

}


