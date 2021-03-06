// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <map>
#include <list>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class TestMap
{
private:

public:
	TestMap()
	{
		testMap = new map<int, T>();
	}

	~TestMap()
	{
		testMap->clear();
		delete testMap;
	}

	map<int, T>* testMap;

	void BuildMapByList(list<pair<int, T>>* listOfT)
	{
		for (list<pair<int, T>>::iterator itForList = listOfT->begin(); itForList != listOfT->end(); itForList++)
		{
			map<int, T>::iterator it = testMap->find(itForList->first);
			if (it != testMap->end())
			{
				it->second = itForList->second;
			}
			else
			{
				testMap->insert(pair<int, T>(itForList->first, itForList->second));
			}
		}
	}
};


int main()
{
	list<pair<int, string>>* listOfString = new list<pair<int, string>>();
	listOfString->insert(listOfString->begin(), pair<int, string>(1, "hello"));
	listOfString->insert(listOfString->begin(), pair<int, string>(2, "my"));
	listOfString->insert(listOfString->begin(), pair<int, string>(3, "name"));
	listOfString->insert(listOfString->begin(), pair<int, string>(4, "is"));
	listOfString->insert(listOfString->begin(), pair<int, string>(5, "junhyung"));
	listOfString->insert(listOfString->begin(), pair<int, string>(6, "song"));
	listOfString->insert(listOfString->begin(), pair<int, string>(7, "!!!"));

	TestMap<string>* test = new TestMap<string>();
	test->BuildMapByList(listOfString);
	map<int, string>* mapByList = test->testMap;

	for (map<int, string>::iterator it = mapByList->begin(); it != mapByList->end(); it++)
	{
		cout << "key: " << it->first << " value: " << it->second << endl;
	}

	string a;
	getline(cin, a);

    return 0;
}

