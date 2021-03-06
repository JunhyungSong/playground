// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <math.h>

using namespace std;

int caculateHappyNumber(int n)
{
	int tmp = n;
	int numOfTens = 0;
	for (int i = 10; i > 0; --i)
	{
		int exp = pow(10, i);

		if (n / exp > 0)
		{
			numOfTens = i;
			break;
		}
	}

	int result = 0;
	int tmpNum = n;
	for (int i = numOfTens; i >= 0; i--)
	{
		int exp = pow(10, i);
		tmpNum = tmpNum / exp;
		result += tmpNum * tmpNum;
		tmpNum = n % exp;
	}

	return result;
}

int solution(int n)
{
	int answer = 0;
	int happyNumber = n;

	while (true)
	{
		happyNumber = caculateHappyNumber(happyNumber);
		answer++;

		if (happyNumber == 1)
			break;
	}

	return answer;
}


int main()
{
	int result = solution(19);

	cout << result << endl;

	string a;
	getline(cin, a);

    return 0;
}

