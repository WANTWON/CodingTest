#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct PointInfo
{
	int x;
	int y;
}POINT;

bool compare(POINT a, POINT b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(void)
{
	int iNum;

	vector<POINT> vecPoint;

	scanf("%d", &iNum);
	
	for (int i = 0; i < iNum; ++i)
	{
		POINT TempPoint;
		scanf("%d %d", &(TempPoint.x), &(TempPoint.y));
		vecPoint.push_back(TempPoint);
	}

	sort(vecPoint.begin(), vecPoint.end(), compare);

	for (int i = 0; i < vecPoint.size(); ++i)
	{
		printf("%d %d\n", vecPoint[i].x, vecPoint[i].y);
	}

	return 0;
}
