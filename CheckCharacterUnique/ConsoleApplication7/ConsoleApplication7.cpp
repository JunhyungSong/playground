// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class CharacterChecker
{
public:
	static bool CheckCharacterUnique(string* givenString)
	{
		if (givenString->size() == 0 || givenString->size() == 1)
			return true;

		bool* characterChecker = new bool[256];
		for (int i = 0; i < 256; i++)
		{
			characterChecker[i] = false;
		}

		for (int i = 0; i < givenString->size(); i++)
		{
			int index = (int)givenString->c_str()[i];

			if (characterChecker[index])
			{
				delete[] characterChecker;
				return false;
			}				
			else
			{
				characterChecker[index] = true;			
			}				
		}

		delete[] characterChecker;
		return true;
	}

private:
};

int main()
{
	string inputString = "";

	getline(cin, inputString);

	CharacterChecker* charChecker = new CharacterChecker();

	while (inputString.compare("") != 0)
	{
		if (charChecker->CheckCharacterUnique(&inputString))
		{
			cout << "Unique!!" << endl;
		}
		else
		{
			cout << "Not Unique!!" << endl;
		}

		getline(cin, inputString);
	}


    return 0;
}

