#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct PointTag
{
	int x;
	int y;
}POINT;


bool Sort(POINT A, POINT B)
{
	if (A.y == B.y)
		return A.x < B.x;

	return A.y < B.y;
}

int main(void)
{
	int iNum;
	scanf("%d", &iNum);
	vector<POINT> vecPoint;

	for (int i = 0; i < iNum; i++)
	{
		POINT Temp;
		scanf("%d %d", &Temp.x, &Temp.y);
		vecPoint.push_back(Temp);
	}

	sort(vecPoint.begin(), vecPoint.end(), Sort);

	for (int i = 0; i < iNum; i++)
		printf("%d %d\n", vecPoint[i].x, vecPoint[i].y);

	return 0;
}
