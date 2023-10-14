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
	//priority_queue<int> PQ;
	priority_queue<int, vector<int>, greater<int>> PQ;

	int tmp;

	while (N--)
	{
		cin >> tmp;

		if (tmp == 0)
		{
			if (PQ.empty()) cout << 0 << "\n";
			else
			{
				cout << PQ.top() << "\n";
				PQ.pop();
			}
		}
		else
		{
			PQ.push(tmp);
		}
	}


	return 0;
}
