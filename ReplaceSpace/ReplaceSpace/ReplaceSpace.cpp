// ReplaceSpace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void replaceSpace(char* str)
{
	int length = 0;
	int numOfSpaces = 0;
	char* end = str;
	
	while (end)
	{
		if (*end == ' ')
		{
			numOfSpaces++;
		}

		length++;
		end++;
	}

	int newLength = length + (numOfSpaces * 2);
	str[newLength] = 0;
	newLength--;
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			str[newLength] = str[i];
			newLength--;
		}
		else
		{
			str[newLength] = '0';
			str[newLength - 1] = '2';
			str[newLength - 2] = '%';
			newLength -= 3;
		}
	}
}

int main()
{
    return 0;
}

