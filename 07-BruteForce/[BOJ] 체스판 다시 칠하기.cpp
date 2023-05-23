#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
string Board[50];

int WB_Count(int x, int y);
int BW_Count(int x, int y);

int main(void)
{
	int iHeight, iWidth;
	int Min_Val = 99999;
	int iCount = 0;

	cin >> iHeight >> iWidth;
	

	for (int i = 0; i < iHeight; i++)
		cin >> Board[i];

	for (int i = 0; i+8 <= iHeight; i++)
	{
		for (int j = 0; j+8 <= iWidth; j++)
		{
			int Temp;
			Temp = min(WB_Count(i, j), BW_Count(i, j));
			if (Temp < Min_Val)
				Min_Val = Temp;
		}
	}

	cout << Min_Val;

	return 0;
}

int WB_Count(int x, int y)
{
	int iCount = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board[x + i][y + j] != WB[i][j])
				iCount++;
		}
	}
	return iCount;
}

int BW_Count(int x, int y)
{
	int iCount = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board[x + i][y + j] != BW[i][j])
				iCount++;
		}
	}
	return iCount;
}
