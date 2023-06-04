#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int iCount = 0;
	int iDemical = 0;
	scanf("%d", &iDemical);
	
	for (int i = 0; i < iDemical; ++i)
	{
		bool bDemical = true;
		int iNum;
		scanf("%d", &iNum); 
		
		for (int j = 2; j < iNum; ++j)
		{
			int iCheckDemical = iNum % j;
			if (iCheckDemical == 0)
				bDemical = false;
		}
		
		if (bDemical && iNum != 1 && iNum != 0)
			iCount++;
		
	}

	printf("%d ", iCount);

	return 0;
}
