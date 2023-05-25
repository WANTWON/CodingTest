

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;


int main(void)
{
	int cnt, k, temp;
	int DP[10001]  ={0,};
	
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt >> k;

	vector<int> Vec(cnt+1);

	for (int i = 1; i <= cnt; i++)
	{
		cin >> Vec[i];
	}

	DP[0] = 1;
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = Vec[i]; j <= k ; j++)
		{
			DP[j] = DP[j] + DP[j - Vec[i]];
		}

	}

	cout << DP[k];


	return 0;
}
