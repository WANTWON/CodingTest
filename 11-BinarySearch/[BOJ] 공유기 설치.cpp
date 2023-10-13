#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int N, M;
vector<int> house;

int FindShareCount(int length)
{
	int cnt = 1;
	int startshare = house[0];
	int endshare;

	for (int i = 1; i < N; i++)
	{
		endshare = house[i];
		if (endshare - startshare >= length)
		{
			cnt++;
			startshare = endshare;
		}
	}

	return cnt;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;



	for (int i = 0; i < N; i++)
	{
		long long houseposition;
		cin >> houseposition;
		house.push_back(houseposition);
	}

	sort(house.begin(), house.end());

	long long start = 1;
	long long end = house.back();
	long long middle;
	long long resultlength =0;
	
	while (start <= end)
	{
		middle = (start + end) / 2;

		int cnt = FindShareCount(middle);
		if (cnt >= M)
		{
			resultlength = middle;
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	cout << resultlength;
	return 0;
}
