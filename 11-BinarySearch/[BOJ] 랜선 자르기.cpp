#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int K, N, ans = 0;
int line[10001];
int maxi = 0;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (maxi < line[i]) maxi = line[i];
	}
	sort(line, line + K);

	long long start = 1;
	long long end = maxi;
	
	while (start <= end)
	{
		long long middle = (start + end) / 2;
		int cablecnt = 0;
		for (int i = 0; i < K; i++)
			cablecnt += (line[i] / middle);

		if (cablecnt >= N)
		{
			start = middle + 1;
			if (ans < middle) ans = middle;
		}
		else
		{
			end = middle - 1;
		}
	}
	cout << ans;
}
