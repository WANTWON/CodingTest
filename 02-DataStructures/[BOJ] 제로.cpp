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
	cin >> N;

	stack<int> S;

	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;

		if (Temp == 0)
			S.pop();
		else
			S.push(Temp);
	}

	int sum = 0;
	while (!S.empty())
	{
		int cur = S.top();
		S.pop();
		sum += cur;
	}

	cout << sum;

	return 0;
}
