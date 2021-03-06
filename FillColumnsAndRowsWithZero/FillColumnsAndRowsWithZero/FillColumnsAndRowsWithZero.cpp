// FillColumnsAndRowsWithZero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void FillColumnsAndRowsWithZero(int** metrix, int rows, int columns)
{
	bool* rowsWithZero = new bool[rows];
	memset(rowsWithZero, 0, rows);

	bool* columnsWithZero = new bool[columns];
	memset(columnsWithZero, 0, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (metrix[i][j] == 0)
			{
				rowsWithZero[i] = true;
				columnsWithZero[j] = true;
			}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (rowsWithZero[i] || columnsWithZero[j])
			{
				metrix[i][j] = 0;
			}
		}
	}
}

int main()
{
    return 0;
}

