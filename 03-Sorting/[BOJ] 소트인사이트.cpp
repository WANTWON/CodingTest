#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int iNum;

	vector<int> vecNumber;

	scanf("%d", &iNum);
	
	while (true)
	{
		vecNumber.push_back(iNum % 10);
		
		if (iNum / 10 == 0)
			break;

		iNum = iNum / 10;
	}

	sort(vecNumber.begin(), vecNumber.end(), compare);

	for (int i = 0; i < vecNumber.size(); ++i)
	{
		printf("%d", vecNumber[i]);
	}

	return 0;
}
