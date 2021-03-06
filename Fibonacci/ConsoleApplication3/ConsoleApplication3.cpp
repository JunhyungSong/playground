#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct int32000
{
	string number[1000];
	int length = 0;
};

int32000 summarizeInt32000(int32000 param1, int32000 param2)
{
	int32000 result;
	result.length = param1.length > param2.length ? param1.length : param2.length;

	for (int i = 0; i <= result.length; i++)
	{
		result.number[i] = "0";
	}

	for (int i = 0; i < result.length; i++)
	{
		int resultNumber = atoi(result.number[i].c_str());

		if (param1.length > i)
		{
			int param1Number = atoi(param1.number[i].c_str());
			resultNumber = resultNumber + param1Number;
		}

		if (param2.length > i)
		{
			int param2Number = atoi(param2.number[i].c_str());
			resultNumber = resultNumber + param2Number;
		}

		if (resultNumber >= 1000000000)
		{
			resultNumber = resultNumber % 1000000000;			

			if (resultNumber < 100000000)
			{
				result.number[i] = "0";
				result.number[i].append(to_string(resultNumber));
			}
			else
			{
				result.number[i] = to_string(resultNumber);
			}
			
			result.number[i + 1] = "1";
		}
		else
		{
			result.number[i] = to_string(resultNumber);
		}
	}

	if (result.number[result.length].compare("0") != 0)
	{
		result.length++;
	}

	return result;
}

int32000 caculateFibonacci(int n)
{
	int32000 fibonacci_n;
	if (n <= 0)
	{
		fibonacci_n.number[0] = "0";
		fibonacci_n.length = 1;
	}
	else if (n == 1 || n == 2)
	{
		fibonacci_n.number[0] = "1";
		fibonacci_n.length = 1;
	}
	else
	{
		int32000 fibonacci_nMinus2;
		fibonacci_nMinus2.number[0] = "0";
		fibonacci_nMinus2.length = 1;

		int32000 fibonacci_nMinus1;
		fibonacci_nMinus1.number[0] = "1";
		fibonacci_nMinus1.length = 1;

		for (int i = 1; i < n; i++)
		{
			fibonacci_n = summarizeInt32000(fibonacci_nMinus1, fibonacci_nMinus2);
			fibonacci_nMinus2 = fibonacci_nMinus1;
			fibonacci_nMinus1 = fibonacci_n;
		}		
	}

	return fibonacci_n;
}


int main()
{
	int number = 0;
	scanf_s("%d", &number);

	while (number >= 0)
	{
		int32000 result = caculateFibonacci(number);

		cout << "Finonacci Number; " << endl;
		for (int i = result.length - 1; i >= 0; i--)
		{
			cout << result.number[i];
		}
		cout << endl;

		cin >> number;
	}	

    return 0;
}

