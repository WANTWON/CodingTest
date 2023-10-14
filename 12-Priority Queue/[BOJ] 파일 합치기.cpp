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

int T, N;
long long tmp;

long long FindMinCost()
{
	priority_queue<long long, vector<long long>, greater<long long>> PQ;

	cin >> N;
	while (N--)
	{
		cin >> tmp;
		PQ.push(tmp);
	}


	long long first, second, ans = 0;
	while (PQ.size() != 1)
	{
		first = PQ.top(); PQ.pop();
		second = PQ.top(); PQ.pop();

		ans += (first + second);
		PQ.push(first + second);
	}

	return ans;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cout << FindMinCost() << "\n";
	}
	
	return 0;
}
