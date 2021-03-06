// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

unsigned long* getNumberOfWayToGetToThePointUsingNFacedDice(int n, int nFaced)
{
	unsigned long* numOfWays = new unsigned long[n + 1];
	numOfWays[0] = 1;
	numOfWays[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (i <= nFaced)
		{
			numOfWays[i] = numOfWays[i - 1] * 2;
		}
		else
		{
			numOfWays[i] = numOfWays[i - 1] * 2 - numOfWays[i - (nFaced + 1)];
		}
	}

	return numOfWays;
}

int main()
{
	int finishingPoint = 0;

	cin >> finishingPoint;

	while (finishingPoint > 0)
	{
		unsigned long* result = getNumberOfWayToGetToThePointUsingNFacedDice(finishingPoint, 6);
		cout << result[finishingPoint] << endl;

		delete[] result;

		cin >> finishingPoint;
	}	

    return 0;
}

