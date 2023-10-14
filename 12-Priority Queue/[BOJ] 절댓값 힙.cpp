#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	int tmp;

	while (N--)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			if (PQ.empty()) cout << 0 << "\n";
			else
			{
				cout << PQ.top().second << "\n";
				PQ.pop();
			}
		}
		else
		{
			PQ.push(make_pair(abs(tmp), tmp));
		}
	}

	return 0;
}
