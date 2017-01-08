#include "WordTree.h"



WordTree::WordTree()
{
	root = NULL;
}


WordTree::~WordTree()
{
	delete(root);
}

void WordTree::Add(string theString)
{
	root = helperAdd(root, theString);
	
}

int WordTree::NumWords()
{
	int count = 0;
	helperNumWords(root, count);
	cout << count;
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
		return new WordNode(NULL, NULL, theString,1);
	}
	if (Node->data == theString)
	{
		Node->frequency = Node->frequency + 1;
		return Node;
	}
	if (theString < Node->data)
	{
		Node = helperAdd(Node->left, theString);
	}
	else
	{
		Node = helperAdd(Node->right, theString);

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
		output << root->data << " " << root->frequency;
		helperOutPut(output, root->right);
	}
}




ostream & operator<<(ostream & output, const WordTree & wordTree)
{
	wordTree.helperOutPut(output, wordTree.root);
	return output;
}
