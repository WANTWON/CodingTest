#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long sum = 0;
	cin >> N;

	stack<int> S;
	long long Temp;

	while (N--)
	{
		cin >> Temp;
		while (!S.empty() && S.top() <= Temp)
		{
			S.pop();
		}
		sum += S.size();
		S.push(Temp);
	}

	cout << sum << " ";

	return 0;
}
