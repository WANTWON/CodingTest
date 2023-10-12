#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int arr[100001];
int M, N, temp;

int BinSearch(int num)
{
	int startIndex = 0;
	int endIndex = M - 1;

	while (startIndex <= endIndex)
	{
		int middle = (startIndex + endIndex) / 2;
		if (arr[middle] > num)
		{
			endIndex = middle - 1;
		}
		else if (arr[middle] < num)
		{
			startIndex = middle + 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	for(int i =0 ; i < M; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr, arr+M);

	cin >> N;
	while (N--)
	{
		cin >> temp;
		cout << binary_search(arr, arr+M, temp) << "\n";
	}

	return 0;
}
