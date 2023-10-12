#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


long long N, M, Max=-1;
long long tree[1000001];

long long FindHeight()
{
	long long start = 0;
	long long end = tree[N-1];
	long long middle = 0;

	while (start <= end)
	{
		middle = (start + end) / 2;
		long long woodsum = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] <= middle)
				continue;
			woodsum += tree[i] - middle;
		}

		if (woodsum >= M)
		{
			start = middle + 1;
			if (middle > Max) Max = middle;
		}
		else
		{
			end = middle - 1;
		}
	}
	return Max;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}
	sort(tree, tree + N);
	cout << FindHeight();
}
