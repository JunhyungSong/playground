// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <thread>
#include <string>
#include <iostream>

using namespace std;

void task1(string str)
{
	cout << str << endl;
}

int main()
{
	thread t1(task1, "hello world");
	thread t2(task1, "my name is june");
	//t1.join();
	t1.detach();
	
    return 0;
}

