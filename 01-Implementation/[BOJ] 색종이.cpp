#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int iBackGround[100][100] = { 0 };
	int iPaperNum = 0;
	scanf("%d", &iPaperNum);
	
	for (int i = 0; i < iPaperNum; ++i)
	{
		int iMinX, iMinY, iMaxX, iMaxY;
		scanf("%d", &iMinX); //minX
		scanf("%d", &iMinY); //minY
		iMaxX = iMinX + 10; //maxX
		iMaxY = iMinY + 10; //maxY

		for (int j = iMinX; j < iMaxX; ++j)
		{
			for (int k = iMinY; k < iMaxY;  ++k)
			{
				iBackGround[j][k] = 1;
			}
		}

		
	}

	int iSum = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			iSum += iBackGround[i][j];
		}

	}

	printf("%d ", iSum);

	return 0;
}
