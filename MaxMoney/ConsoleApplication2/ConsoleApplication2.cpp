// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

int max = 0;

void findMax(int nextCol, int nextRow, int maxCol, int maxRow, int** graph, int sum)
{
	if (nextCol >= maxCol || nextRow >= maxRow)
		return;

	sum += graph[nextCol][nextRow];

	if (nextCol + 1 == maxCol && nextRow + 1 == maxRow)
		if (sum > max)
			max = sum;

	findMax(nextCol + 1, nextRow, maxCol, maxRow, graph, sum);
	findMax(nextCol, nextRow + 1, maxCol, maxRow, graph, sum);
}

void findMaxMoney(int i, char* money)
{
	int n;
	int** graph = new int*[i];
	for (n = 0; n <= i; n++)
	{		
		graph[n] = new int[i];
	}

	n = 0;
	char* value;
	char* context;
	value = strtok_s(money, ",", &context);
	while (value)
	{
		if (value[0] == '(')
			value++;

		int lastIndex = strlen(value) - 1;
		if (value[lastIndex] == ')')
			value[lastIndex] = NULL;

		graph[n / i][n % i] = atoi(value);

		n++;
	    value =	strtok_s(NULL, ",", &context);
	}

	findMax(0, 0, i, i, graph, 0);
}

int main()
{
	char str[] = "(1,7,5,2),(5,12,500,6),(100,9,23,16),(16,4,5,9)";
	findMaxMoney(4, str);
	printf_s("%d", max);
	char a;
	scanf_s("%c", &a);

    return 0;
}

