#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 15

using namespace std;

bool visited[200000];
int Count[200000];
vector<int> Graph[200000];
int first = 1;


void dfs(int First)
{
	if (visited[First])
		return;

	visited[First] = true;
	Count[First] = first;
	first++;

	//오름차순 정렬!!!
	sort(Graph[First].begin(), Graph[First].end());
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
	{
		cout << Count[i] << "\n";
	}

	return 0;
}
