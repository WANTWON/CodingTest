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
long long tmp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<long long, vector<long long>, greater<>> Q;


	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		cin >> tmp;
		Q.push(tmp);
		if (Q.size() > N)
		{
			Q.pop();
		}
	}
	cout << Q.top() << "\n";

	return 0;
}
