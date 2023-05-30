#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int iNum;
	scanf("%d", &iNum);

	vector<int> vecNum;
	
	for (int i = 0; i < iNum; ++i)
	{
		int Number;
		scanf("%d", &Number);
		vecNum.push_back(Number);
	}

	sort(vecNum.begin(), vecNum.end());

	for (int i = 0; i < iNum; ++i)
	{
		printf("%d\n", vecNum[i]);
	}

	return 0;
}
