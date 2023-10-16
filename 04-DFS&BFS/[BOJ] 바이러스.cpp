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

int N, M, cnt =0;

vector<int> graph[101];
bool visited[101];

void dfs(int start)
{
	visited[start] = true;

	if (graph[start].size() == 0)
		return;

	for (auto edge : graph[start])
	{
		if (!visited[edge])
		{
			dfs(edge);
			cnt++;
		}
	}
	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >>M;

	while (M--)
	{
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	dfs(1);

	cout << cnt << endl;
	
	return 0;
}
