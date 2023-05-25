#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> Graph;
vector<int> isVisited;
int step = 0;

void dfs(int First, int level)
{
	if (isVisited[First] > 0)
		return;

	isVisited[First] = level;

	sort(Graph[First].begin(), Graph[First].end());

	for (auto iter : Graph[First])
	{
		dfs(iter, level + 1);
	}
}

void bfs(int First)
{
	queue<int> q;
	q.push(First);

	step++;
	isVisited[First] = step;

	while (!q.empty())
	{
		int Inq = q.front();

		q.pop();
		for (auto iter : Graph[Inq])
		{
			if (isVisited[iter] == 0)
			{
				step++;
				isVisited[iter] = step;
				q.push(iter);
			}
		}
	}

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, First;
	cin >> n >> m >> First;

	Graph.resize(n + 1);
	isVisited.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(Graph[i].begin(), Graph[i].end());

	bfs(First);

	for (int i = 1; i <= n; i++)
		cout << isVisited[i] << "\n";

	return 0;
}
