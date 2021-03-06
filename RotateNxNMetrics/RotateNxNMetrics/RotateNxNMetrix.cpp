// RotateNxNMetrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void RotateMetrix(int** metrix, int n, int depth)
{
	for (int i = depth; i < n - depth * 2; i++)
	{
		int tmp = metrix[i][n - 1 - depth];
		metrix[i][n - 1 - depth] = metrix[depth][i];

		int tmp2 = metrix[n - 1 - depth][n - 1 - i];
		metrix[n - 1 - depth][n - 1 - i] = tmp;

		tmp = metrix[n - 1 - i][depth];
		metrix[n - 1 - i][depth] = tmp2;

		metrix[depth][i] = tmp;
	}

	if (n - depth * 2 > 2)
	{
		RotateMetrix(metrix, n, ++depth);
	}
}

int main()
{
    return 0;
}

