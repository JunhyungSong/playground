// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void RemoveDuplicatedCharacter(list<char>* charList)
{
	bool* chars = new bool[256];
	for (int i = 0; i < 256; i++)
	{
		chars[i] = false;
	}

	list<char>::iterator it = charList->begin();
	while (true)
	{
		if (chars[*it])
		{
			it = charList->erase(it);
		}
		else
		{
			chars[*it] = true;
			it++;
		}
		
		if (it == charList->end())
			break;
	}
}

int main()
{
	string a;
	getline(cin, a);

	while (a.compare("") != 0)
	{
		list<char> b(a.c_str(), a.c_str() + a.size());
		RemoveDuplicatedCharacter(&b);
		list<char>::iterator it = b.begin();
		while (true)
		{
			cout << *it;
			it++;

			if (it == b.end())
				break;			
		}
		cout << endl;

		getline(cin, a);
	}

    return 0;
}

