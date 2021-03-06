// ClusteringVectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

#define THRESHOLD 0.001f

bool Converge(float** oldCenters, float** currentCenters, int mClusters, int dDimensions)
{
	for (int i = 0; i < mClusters; i++)
	{
		for (int j = 0; j < dDimensions; j++)
		{
			if (abs(oldCenters[i][j] - currentCenters[i][j]) > THRESHOLD)
			{
				return false;
			}
		}
	}

	return true;
}

float CaculateDistance(float* points, float* center, int dDimensions)
{
	float distance = 0.0f;
	for (int i = 0; i < dDimensions; i++)
	{
		distance += pow(points[i] - center[i], 2);
	}

	return distance;
}

void KNearestNeighbor(string fileName, int nVectors, int mClusters, int dDimensions)
{
	fstream is;
	is.open(fileName, ios::in | ios::binary);

	if (is.fail())
	{
		return;
	}

	int fileSize = nVectors * dDimensions;
	float* buffer = new float[fileSize];
	is.read(reinterpret_cast<char*>(buffer), fileSize * sizeof(float));
	float a = buffer[0];
	float b = buffer[1];
	float c = buffer[2];

	float** oldCenters = new float*[mClusters];
	for (int i = 0; i < mClusters; i++)
	{
		oldCenters[i] = new float[dDimensions];
		memset(oldCenters[i], 0, dDimensions * sizeof(float));
	}

	float** currentCenters = new float*[mClusters];
	for (int i = 0; i < mClusters; i++)
	{
		currentCenters[i] = new float[dDimensions];

		for (int j = 0; j < dDimensions; j++)
		{
			currentCenters[i][j] = buffer[i * dDimensions + j];
		}
	}
	
	int* belongings = new int[nVectors];
	memset(belongings, 0, nVectors * sizeof(int));

	while (!Converge(oldCenters, currentCenters, mClusters, dDimensions))
	{
		for (int i = 0; i < nVectors; i++)
		{
			float minDistance = -1.0f;
			int minIndex = -1;
			for (int j = 0; j < mClusters; j++)
			{
				float distance = CaculateDistance(&buffer[i * dDimensions], currentCenters[j], dDimensions);

				if (minDistance == -1.0f || minDistance > distance)
				{
					minDistance = distance;
					minIndex = j;
				}
			}

			belongings[i] = minIndex;
		}

		delete[] oldCenters;
		oldCenters = currentCenters;

		float** tempCenters = new float*[mClusters];
		for (int i = 0; i < mClusters; i++)
		{
			tempCenters[i] = new float[dDimensions];
			memset(tempCenters[i], 0, dDimensions * sizeof(float));
		}
		int* tempCount = new int[mClusters];
		memset(tempCount, 0, mClusters * sizeof(int));

		for (int i = 0; i < nVectors; i++)
		{
			tempCount[belongings[i]]++;

			for (int j = 0; j < dDimensions; j++)
			{
				tempCenters[belongings[i]][j] += buffer[i * dDimensions + j];
			}
		}

		for (int i = 0; i < mClusters; i++)
		{
			if (tempCount[i] != 0)
			{
				for (int j = 0; j < dDimensions; j++)
				{
					tempCenters[i][j] /= tempCount[i];
				}
			}
		}

		currentCenters = tempCenters;
	}

	for (int i = 0; i < nVectors; i++)
	{
		cout << i << "th Vector: " << belongings[i] << " / ";

		if (i != 0 && i % 4 == 0)
		{
			cout << endl;
		}
	}

	for (int i = 0; i < mClusters; i++)
	{
		cout << i << "th Cluster means (";

		for (int j = 0; j < dDimensions; j++)
		{
			if (j != 0)
			{
				cout << ", ";
			}

			cout << currentCenters[i][j];
		}

		cout << ")" << endl << endl;
	}

	delete[] belongings;
	delete[] buffer;
	for (int i = 0; i < mClusters; i++)
	{
		delete[] oldCenters[i];
	}
	delete[] oldCenters;
	for (int i = 0; i < mClusters; i++)
	{
		delete[] currentCenters[i];
	}
	delete[] currentCenters;
}

int main(int argc, char** argv)
{
	string fullPath(argv[0]);
	string path = fullPath.substr(0, fullPath.find_last_of("\\"));
	KNearestNeighbor(path + "\\features_32dim_float_22464samples.data", 22464, 10, 32);

	string holder;
	getline(cin, holder);

    return 0;
}

