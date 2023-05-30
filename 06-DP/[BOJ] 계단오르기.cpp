#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main(void)
{
	int cnt;
	int totalscore = 0;
	int* DP;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	int* step = new int[cnt];
	DP = new int[cnt];

	for (int i = 0; i < cnt; i++)
		cin >> step[i];
	
	DP[0] = step[0];
	DP[1] = step[0] + step[1];
	DP[2] = max(step[1], step[0]) + step[2];
	
	for (int i = 3 ; i < cnt; i++)
	{
		DP[i] = max(DP[i - 2], DP[i-3] + step[i-1]) + step[i];
		
	}

	cout << DP[cnt-1] << "\n";

	return 0;
}
