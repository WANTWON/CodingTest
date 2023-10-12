#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
int N;
int arr[1001];
vector<int> sumResult;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+N);
	
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			sumResult.push_back(arr[j] + arr[k]);
		}
	}

	sort(sumResult.begin(), sumResult.end());
	sumResult.erase(unique(sumResult.begin(), sumResult.end()), sumResult.end());

	for(int i = N - 1; i >= 0; i--)
	{
		for (int j = 1; j < N; j++)
		{
			int findnum = arr[i] - arr[i - j];
			if (binary_search(sumResult.begin(), sumResult.end(), findnum))
			{
				cout << arr[i];
				return 0;
			}
		}
	}
	return 0;
}
