#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Graph[200000];
int Count[200000];
bool isVisited[200000];
int step = 1;

void dfs(int First)
{
	if (isVisited[First])
		return;


	
	isVisited[First] = true;
	Count[First] = step;
	step++;

	sort(Graph[First].rbegin(), Graph[First].rend());

	for (auto iter : Graph[First])
	{
		dfs(iter);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m , First;
	cin >> n >> m >> First;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	dfs(First);

	for (int i = 1; i <= n; i++)
		cout << Count[i] << "\n";

	return 0;
}
