// SparseMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct CsrMatrix
{
	int columns;
	int rows;
	int* ar;
	int* iar;
	int* jar;
};

CsrMatrix* ConvertMatrixToCsr(int** matrix, int rows, int columns)
{
	int countOfNoneZero = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] != 0)
			{
				countOfNoneZero++;
			}
		}
	}

	CsrMatrix* csr = new CsrMatrix();
	csr->columns = columns;
	csr->rows = rows;
	csr->ar = new int[countOfNoneZero];
	csr->jar = new int[countOfNoneZero];
	csr->iar = new int[rows + 1];
	csr->iar[0] = 0;

	int currentIndex = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] != 0)
			{
				csr->ar[currentIndex] = matrix[i][j];
				csr->jar[currentIndex] = j;
				currentIndex++;
			}
		}

		csr->iar[i + 1] = currentIndex;
	}

	return csr;
}

int** ConvertCsrToMatrix(CsrMatrix* csr)
{
	int** matrix = new int*[csr->rows];
	for (int i = 0; i < csr->rows; i++)
	{
		matrix[i] = new int[csr->columns];
		memset(matrix[i], 0, csr->columns * sizeof(int));
	}

	for (int i = 0; i < csr->rows; i++)
	{
		for (int j = csr->iar[i]; j < csr->iar[i + 1]; j++)
		{
			matrix[i][csr->jar[j]] = csr->ar[j];
		}
	}

	return matrix;
}

CsrMatrix* MultiplyCsrMatrixes(CsrMatrix* leftMatrix, CsrMatrix* rightMatrix)
{
	if (leftMatrix->columns != rightMatrix->rows)
	{
		return NULL;
	}

	int** matrix = new int*[leftMatrix->rows];
	for (int i = 0; i < leftMatrix->rows; i++)
	{
		matrix[i] = new int[rightMatrix->columns];
		memset(matrix[i], 0, rightMatrix->columns * sizeof(int));
	}

	for (int i = 0; i < leftMatrix->rows; i++)
	{
		for (int j = leftMatrix->iar[i]; j < leftMatrix->iar[i + 1]; j++)
		{
			for (int x = rightMatrix->iar[leftMatrix->jar[j]]; x < rightMatrix->iar[leftMatrix->jar[j] + 1]; x++)
			{
				matrix[i][x] += leftMatrix->ar[j] * rightMatrix->ar[x];
			}
		}
	}

	CsrMatrix* multipliedMatrix = ConvertMatrixToCsr(matrix, leftMatrix->rows, rightMatrix->columns);

	for (int i = 0; i < leftMatrix->rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return multipliedMatrix;
}

void PrintCsrMatrix(CsrMatrix* csr) 
{
	for (int i = 0; i < csr->rows; i++) 
	{
		int c = 0;
		for (int j = csr->iar[i]; j < csr->iar[i + 1]; j++) 
		{
			for (; c < csr->jar[j]; c++)
			{
				cout << "0, ";
			}

			cout << csr->ar[j] << ", ";
			c++;
		}

		for (; c < csr->columns; c++)
		{
			cout << "0, ";
		}

		cout << endl;
	}
}

int main()
{
	int** test = new int*[4];
	test[0] = new int[4] {0, 0, 0, 0};
	test[1] = new int[4] {5, 8, 0, 0};
	test[2] = new int[4] {0, 0, 3, 0};
	test[3] = new int[4] {0, 6, 0, 0};

	CsrMatrix* csr = ConvertMatrixToCsr(test, 4, 4);
	PrintCsrMatrix(csr);

	cout << endl << endl;

	CsrMatrix* multiply = MultiplyCsrMatrixes(csr, csr);
	PrintCsrMatrix(multiply);

	string holder;
	getline(cin, holder);

    return 0;
}

