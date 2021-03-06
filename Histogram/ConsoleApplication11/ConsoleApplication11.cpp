// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

#include <vector>
#include <algorithm>
using namespace std;

int getMaxContainingNth(vector<int> histogram, int begin, int end, int containingN)
{
	int max = 0;

	for (int i = begin; i < containingN; i++)
	{
		for (int j = containingN + 1; j <= end; j++)
		{
			int area = min(histogram[i], histogram[j]) * (j - i - 1);
			if (area > max)
			{
				max = area;
			}
		}
	}

	return max;
}

int getMax(vector<int> histogram, int begin, int end)
{
	int gap = end - begin;

	if (gap < 2)
		return 0;

	if (gap == 2)
		return histogram[gap - 1];

	int middle = gap / 2 + begin;
	int m1 = getMax(histogram, begin, middle);
	int m2 = getMax(histogram, middle, end);
	int m3 = getMaxContainingNth(histogram, begin, end, middle);

	return max(m1, max(m2, m3));
}

int solution(vector<int> histogram)
{
	if (histogram.size() < 3)
		return 0;

	if (histogram.size() == 3)
		return histogram[1];

	int answer = getMax(histogram, 0, histogram.size() - 1);
	return answer;
}

int main()
{
	vector<int> sample = { 2, 2, 2, 3 };
	vector<int> sample2 = { 6, 5, 7, 3, 4, 2 };
	cout << solution(sample2) << endl;

	string a;
	
	getline(cin, a);

    return 0;
}

