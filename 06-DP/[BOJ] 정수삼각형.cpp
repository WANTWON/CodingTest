#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;
int DP[500][500];

int main(void)
{
	int cnt;
	int MaxSum = 0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> DP[i][j];
	}
	MaxSum = DP[0][0];

	for (int i = 1; i < cnt; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				DP[i][0] += DP[i-1][0];
			else if (j == i)
				DP[i][j] += DP[i-1][j-1];
			else
				DP[i][j] += max(DP[i-1][j-1], DP[i-1][j]);

			if ((i == cnt - 1))
				MaxSum = max(DP[i][j], MaxSum);
		}
	
	cout << MaxSum <<"\n";

	return 0;
}
