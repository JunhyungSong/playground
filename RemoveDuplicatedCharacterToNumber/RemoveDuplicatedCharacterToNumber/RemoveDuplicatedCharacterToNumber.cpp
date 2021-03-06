// RemoveDuplicatedCharacterToNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <string.h>

using namespace std;

int caculateNumberOfTens(int num)
{
	int numberOfTens = 0;
	while (true)
	{
		if ((num / pow(10, numberOfTens + 1)) > 0)
			numberOfTens++;
		else
			break;
	}

	return numberOfTens;
}

char* removeDuplicatedCharacterToNumber(char* str)
{
	int length = 0;
	int convertedLength = 0;
	char last = 0;
	char* end = str;
	int duplicatedCount = 1;

	while (end)
	{
		if (last != *end)
		{
			if (duplicatedCount >= 10)
			{
				convertedLength += caculateNumberOfTens(duplicatedCount);
			}

			last = *end;
			duplicatedCount = 1;
			convertedLength += 2;
		}
		else
		{
			duplicatedCount++;
		}

		end++;
		length++;
	}

	if (length <= convertedLength)
	{
		return str;
	}
	else
	{
		last = 0;
		end = str;
		duplicatedCount = 1;
		char* newStr = new char[convertedLength + 1];
		newStr[convertedLength] = 0;
		int convertedIndex = 0;
		char buffer[10];

		while (end)
		{
			if (last != *end)
			{
				if (last != 0)
				{
					itoa(duplicatedCount, buffer, 10);
					length = strlen(buffer);
					for (int i = 0; i < length; i++)
					{
						newStr[convertedIndex] = buffer[i];
						convertedIndex++;
					}
				}

				newStr[convertedIndex] = *end;
				convertedIndex++;
				last = *end;
				duplicatedCount = 1;				
			}
			else
			{
				duplicatedCount++;
			}

			end++;
		}

		return newStr;
	}
}

int main()
{
    return 0;
}

