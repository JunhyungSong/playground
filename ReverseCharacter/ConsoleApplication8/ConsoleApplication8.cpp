// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

char* reverse(char* str)
{
	int length = strlen(str);

	for (int i = 0; i < length / 2; i++)
	{
		char tmp = str[length - 1 -i];
		str[length - 1 - i] = str[i];
		str[i] = tmp;
	}

	return str;
}

int main()
{
	char str[] = { 'h', 'a', 'h', 'o', 0 };
	cout << reverse(str) << endl;

	string haha;
	
	getline(cin, haha);

    return 0;
}

