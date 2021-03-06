// CheckAnagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

using namespace std;

bool checkAnagram(char* str1, char* str2)
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);

	if (length1 != length2)
		return false;

	unsigned int ascii[256];
	memset(ascii, 0, 256 * sizeof(unsigned int));

	while (str1)
	{
		ascii[*str1]++;
		str1++;
	}

	while (str2)
	{
		if (ascii[*str2] == 0)
			return false;

		ascii[*str2]--;
		str2++;
	}

	return true;
}

int main()
{
    return 0;
}

