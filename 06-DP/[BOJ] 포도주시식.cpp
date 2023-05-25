#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;


int main(void)
{
	int cnt;
	int DP[10001] = {0};
	int Grape[10001] = {0};
	int MaxNum = 0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		cin >> Grape[i];
	}

	DP[0] = MaxNum = Grape[0];
	DP[1] = MaxNum =  DP[0] + Grape[1];
	DP[2] = MaxNum = max(max(DP[0], Grape[1]) + Grape[2], DP[1]);
	
	for (int i = 3; i < cnt; i++)
	{
		DP[i] = max(max(DP[i - 2], DP[i - 3] + Grape[i - 1]) + Grape[i], DP[i-1]);

		if (MaxNum < DP[i])
			MaxNum = DP[i];
	}

	cout << MaxNum << "\n";

	return 0;
}
