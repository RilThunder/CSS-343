/**
	Assignment 1: Word Counting using a Binary Search Tree
	WordTree.h
	Purpose: Create a header file for the WordTree

	@author Thuan Tran, CSSE Junior at the University of Washington Bothell
	@version 1 January 8th,2017
*/

#ifndef WORD_H
#define WORD_H
#include <string>
using namespace std;
#include <string>
#include <iostream>


class WordTree
{
public:
	/**
		A default constructor for the WordTree
	*/	
	WordTree();

	/**
		A destrutor for the Word Tree
	*/
	~WordTree();

	/**
		This method can be use to add a string into the WordTree
		If the string already existed, it will update the frequency of the string
		@param theString the string that will be add
	*/
	void Add(string theString);
	
	/**
		This method can be use to count how many distinct word are there in the WordTree
		@return an integer that show how many words are there in the WordTree
	*/
	int NumWords();
	
	
private:
	class WordNode
	{
	public:
		WordNode *left;
		WordNode *right;
		string data;
		int frequency;
		WordNode() : left(NULL), right(NULL), data(NULL), frequency(0) {} // Default constructor for WordNode
		WordNode(WordNode *leftData, WordNode *rightData, string theData,int freq) : left(leftData), right(rightData),
			data(theData), frequency(freq){} // Constructor using initializing list 
		
	};
	
	WordNode *root;
	
	/**
		This private method is used to delete the Tree by using post order traversal
		@param Node the pointer to the Node to delete
	*/
	void deleteTree(WordNode *Node);

	/**
		This private method is used to add the word into the correct position
		@param Node the pointer to the place to add
		@param theString the string to add
		@return WordNode an updated Node
	*/
	WordNode * helperAdd(WordNode *Node, string theString);
	
	/**
		This method overload the output operator and it will display each word and frequency in the string
	*/
	friend ostream& operator<<(ostream &output, const WordTree &wordTree);
	
	/**
		This method is used to count the word in the tree
		@param Node the pointer to the Node we are currently at
		@count an integer value that we will increment using reference
	*/
	void helperNumWords(WordNode *Node, int &count);

	/**
		This is a private helper method to display the output
	*/
	void helperOutPut(ostream& output, WordNode *root) const;
	//
};
#endif


