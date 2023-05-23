#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;


int main(void)
{
	int cnt;
	int DP[1001][3];
	int minNum = 1001;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> DP[i][j];
		}
	}

	for (int i = 1; i < cnt; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			DP[i][j] += min(DP[i-1][(j + 1) % 3], DP[i-1][(j + 2) % 3]);
		}
	}

	cout << min(DP[cnt-1][2], min(DP[cnt - 1][0], DP[cnt - 1][1])) << "\n";


	return 0;
}