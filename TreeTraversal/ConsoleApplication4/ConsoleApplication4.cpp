// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <iostream>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T value;
	BinaryTreeNode* firstChild;
	BinaryTreeNode* secondChild;

	BinaryTreeNode<T>()
	{
		firstChild = NULL;
		secondChild = NULL;
	}
};

template <typename T>
void getListOfTreeNodes(BinaryTreeNode<T>* header, list<BinaryTreeNode<T>*>* listOfTreeNode)
{
	listOfTreeNode->push_back(header);

	if (header->firstChild != NULL)
	{
		getListOfTreeNodes(header->firstChild, listOfTreeNode);
	}

	if (header->secondChild != NULL)
	{
		getListOfTreeNodes(header->secondChild, listOfTreeNode);
	}
}

int main()
{
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>();
	node1->value = 1;

	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>();
	node2->value = 2;

	BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>();
	node3->value = 3;

	BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>();
	node4->value = 4;

	BinaryTreeNode<int>* node5 = new BinaryTreeNode<int>();
	node5->value = 5;

	BinaryTreeNode<int>* node6 = new BinaryTreeNode<int>();
	node6->value = 6;

	node1->firstChild = node2;
	node1->secondChild = node3;
	node2->firstChild = node4;
	node2->secondChild = node5;
	node3->firstChild = node6;

	list<BinaryTreeNode<int>*>* listOfTreeNodes = new list<BinaryTreeNode<int>*>();
	getListOfTreeNodes<int>(node1, listOfTreeNodes);

	while (!listOfTreeNodes->empty())
	{
		cout << listOfTreeNodes->front()->value << endl;
		listOfTreeNodes->pop_front();
	}

	int end = 0;
	cin >> end;

    return 0;
}

