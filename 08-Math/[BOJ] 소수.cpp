#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int iDemicalMin = 9999;
	int iDemicalTotal = 0;
	int iDemicalCount = 0;
	int iMinNum = 0;
	int iMaxNum = 0;
	scanf("%d", &iMinNum);
	scanf("%d", &iMaxNum);
	
	for (int i = iMinNum; i <= iMaxNum; ++i)
	{
		bool bDemical = true;
		int iNum = i;

		for (int j = 2; j < iNum; ++j)
		{
			int iCheckDemical = iNum % j;
			if (iCheckDemical == 0)
				bDemical = false;
		}
		
		if (bDemical && iNum != 1 && iNum != 0)
		{
			iDemicalTotal += iNum;
			iDemicalCount++;
			if (iNum < iDemicalMin)
			{
				iDemicalMin = iNum;
			}
		}
		
		
	}

	if(iDemicalCount == 0)
		printf("%d ", -1);
	else
	{
		printf("%d ", iDemicalTotal);
		printf("%d ", iDemicalMin);
	}
	

	return 0;
}
