/**
	Assignment 1: Word Counting using a Binary Search Tree
	WordTree.cpp
	Purpose: Implementation file for the WordTree.cpp

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1 January 8th,2017
*/

#include "WordTree.h"

WordTree::WordTree()
{
	root = NULL;
}


WordTree::~WordTree()
{
	deleteTree(root); // starting delete at the root and go all the way down using post order
}

void WordTree::Add(string theString)
{
	root = helperAdd(root, theString);
	
}

int WordTree::NumWords()
{ 
	int count = 0;
	helperNumWords(root, count); // Increment count by manipulating the memory directly
	return count;
}




void WordTree::deleteTree(WordNode * Node)
{
	if (Node != NULL)
	{
		deleteTree(Node->left);
		deleteTree(Node->right);
		delete Node;
	}

}

WordTree::WordNode * WordTree::helperAdd(WordNode * Node, string theString)
{
	if (Node == NULL)
	{
		return new WordNode(NULL, NULL, theString,1); // We have found a place to insert
	}
	if (Node->data == theString) // The string is already there, update the frequency
	{
		Node->frequency = Node->frequency + 1;
		return Node;
	}
	if (theString < Node->data) // Using binary search to find a place
	{
		Node->left = helperAdd(Node->left, theString); // Recursively travel and update the Node 
	}
	else
	{
		Node->right = helperAdd(Node->right, theString);

	}
	return Node;

}

void WordTree::helperNumWords(WordNode * root, int &count)
{
	if (root == NULL)
	{
		return;
	}
	count++; // Preorder traversal
	helperNumWords(root->left, count);
	helperNumWords(root->right, count);
	
}

void WordTree::helperOutPut(ostream & output, WordNode * root) const
{
	if (root != NULL)
	{
		helperOutPut(output, root->left);
		// Inorder traversal
		output << root->data << " " << root->frequency << " " << endl;
		helperOutPut(output, root->right);
	}
}

ostream & operator<<(ostream & output, const WordTree & wordTree)
{
	wordTree.helperOutPut(output, wordTree.root);
	return output;
}
