#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>

using namespace std;

int N;

vector<vector<int>> Q(200001);
priority_queue<unsigned int> noodles;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int deadline, noodle;
	while (N--)
	{
		cin >> deadline >> noodle;
		Q[deadline].push_back(noodle);
	}

	unsigned int noodlesum = 0;
	for (int i = 200000; i > 0; i--)
	{
		for (auto noodle : Q[i])
		{
			noodles.push(noodle);
		}

		if (noodles.empty()) continue;
		noodlesum += noodles.top();
		noodles.pop();
	}

	cout << noodlesum << endl;

	return 0;
}
