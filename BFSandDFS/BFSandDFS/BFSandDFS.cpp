// BFSandDFS.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* left;
	Node* right;
};

template <typename T>
void BFS(queue<Node<T>*>& queueForSearch)
{
	if (queueForSearch.size() == 0)
	{
		return;
	}

	Node<T>* node = queueForSearch.pop();

	// do something for node

	if (node->left)
	{
		queueForSearch.push(node->left);
	}

	if (node->right)
	{
		queueForSearch.push(node->right);
	}

	BFS(queueForSearch);
}

template <typename T>
void DFS(stack<Node<T>*>& stackForSearch)
{
	if (stackForSearch.size() == 0)
	{
		return;
	}

	Node<T>* node = stackForSearch.pop();

	// do something for node

	if (node->left)
	{
		stackForSearch.push(node->left);
	}

	if (node->right)
	{
		stackForSearch.push(node->right);
	}

	DFS(stackForSearch);
}

int main()
{
    return 0;
}

