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

	stack<pair<int, int>> S;
	S.push({ 10000000000, 0 });
	vector<int> Collision(N);
	
	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;

		while (S.top().first < Temp)
		{
			S.pop();
		}
		Collision[i] = S.top().second;

		S.push({ Temp, i+1 });
	}

	for (int i = 0; i < N; i++)
		cout << Collision[i] << " ";

	return 0;
}
