#ifndef WORD_H
#define WORD_H
#include <string>
using namespace std;
#include <string>
#include <iostream>




class WordTree
{
public:
	
	WordTree();
	~WordTree();
	void Add(string theString);
	int NumWords();
	
	
	
private:
	class WordNode
	{
	public:
		WordNode *left;
		WordNode *right;
		string data;
		int frequency;
		WordNode() : left(NULL), right(NULL), data(NULL), frequency(0) {}
		WordNode(WordNode *leftData, WordNode *rightData, string theData,int freq) : left(leftData), right(rightData),
			data(theData), frequency(freq){}
		
	};
	
	WordNode *root;
	void deleteTree(WordNode *Node);
	WordNode * helperAdd(WordNode *Node, string theString);
	friend ostream& operator<<(ostream &output, const WordTree &wordTree);
	void helperNumWords(WordNode *Node, int &count);
	void helperOutPut(ostream& output, WordNode *root) const;

};
#endif


