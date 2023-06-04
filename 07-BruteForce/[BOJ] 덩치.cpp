#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct BodyTag
{
	int iWeight;
	int iHeight;
	int iIndex = 0;

}BODY;


int main(void)
{
	int iNum;
	scanf("%d", &iNum);
	vector<BODY> vecBodyCharts;
	vecBodyCharts.reserve(0);

	for (int i = 0; i < iNum; ++i)
	{
		BODY InputBody;
		scanf("%d %d", &(InputBody.iWeight), &(InputBody.iHeight));
		vecBodyCharts.push_back(InputBody);

	}


	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < vecBodyCharts.size(); ++j)
		{
			if ((vecBodyCharts[i].iHeight < vecBodyCharts[j].iHeight && vecBodyCharts[i].iWeight < vecBodyCharts[j].iWeight))
				vecBodyCharts[i].iIndex++;

		}
		printf("%d ", vecBodyCharts[i].iIndex + 1);
	}

	return 0;
}
