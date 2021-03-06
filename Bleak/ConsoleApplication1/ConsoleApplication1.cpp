// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static bool IsBleak(int m)
{
	int len = 0;
	while ((1 << len) + len < m)
		len++;
	for (int i = len; i >= 0; i--)
		if (m >= (1 << i) + 1)
			m -= (1 << i) + 1;

	return m != 0;
}

int main()
{
	bool isBleak = IsBleak(4);
	printf(isBleak ? "true" : "false");
	char a;
	scanf_s("%c", &a);

    return 0;
}

