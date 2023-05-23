#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int iNum;
	scanf("%d", &iNum);
	vector<int> Points(iNum);
	vector<int> PointsNotDuple(iNum);

	for (int i = 0; i < iNum; i++)
	{
		scanf("%d", &Points[i]);
		PointsNotDuple[i] = Points[i];

	}

	sort(PointsNotDuple.begin(), PointsNotDuple.end());
	PointsNotDuple.erase(unique(PointsNotDuple.begin(), PointsNotDuple.end()), PointsNotDuple.end());
	
	for (int i = 0; i < iNum; i++)
		printf("%d ", lower_bound(PointsNotDuple.begin(), PointsNotDuple.end(), Points[i]) - PointsNotDuple.begin());
	
	return 0;
}
