#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Graph[200000];
int Count[200000];
bool isVisited[200000];

void dfs(int First, int level)
{
	if (isVisited[First])
		return;
	
	isVisited[First] = true;
	Count[First] = level;
	
	sort(Graph[First].begin(), Graph[First].end());

	for (auto iter : Graph[First])
	{
		dfs(iter, level+1);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(Count, 200000, -1);

	int n, m , First;
	cin >> n >> m >> First;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	dfs(First, 0);

	for (int i = 1; i <= n; i++)
		cout << Count[i] << "\n";

	return 0;
}
