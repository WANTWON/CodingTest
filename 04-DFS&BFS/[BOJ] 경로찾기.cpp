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

int arr[102][102];
bool visited[102];

int N;

bool dfs(int start, int tar)
{
	fill(visited, visited + N+2, 0);
	stack<int> stk;
	stk.push(start);

	while (!stk.empty())
	{
		int cur = stk.top(); 
		stk.pop();

		if (visited[cur]) continue;
		if (cur != start) visited[cur] = 1;

		for (int next = 0; next < N; next++)
		{
			if (visited[next]) continue;
			if (arr[cur][next])
			{
				if(next == tar)
					return true;
				stk.push(next);
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << dfs(i, j) << ' ';
		cout << '\n';
	}
	return 0;
}
