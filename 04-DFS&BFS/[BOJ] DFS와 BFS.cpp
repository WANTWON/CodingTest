#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int visited[1001];
vector<int> Edge[1001];


void DFS_Recursion(int index)
{
	cout << index << " ";

	for (int i = 0; i < Edge[index].size(); i++)
	{
		if (visited[Edge[index][i]] > 0)
			continue;

		visited[Edge[index][i]]++;
		DFS_Recursion(Edge[index][i]);
	}
}

void DFS_Stack(int start)
{
	stack<int> S;
	S.push(start);

	while (!S.empty())
	{
		int cur = S.top();
		S.pop();

		if (visited[cur] > 0)
			continue;
		visited[cur]++;
		cout << cur << " ";

		for (int i = 0; i < Edge[cur].size(); i++)
		{
			//스택의 특성상 정점을 역순으로 넣어줘야함
			int Next = Edge[cur][Edge[cur].size() - 1 - i];
			if (visited[Next] > 0)
				continue;

			S.push(Next);
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int E1, E2;
		cin >> E1 >> E2;
		Edge[E1].push_back(E2);
		Edge[E2].push_back(E1);
	}
	//정점의 번호가 적은 것을 먼저 방문하기 위해
	for (int i = 1; i <= N; i++)
		sort(Edge[i].begin(), Edge[i].end());


	//DFS
	//visited[V]++;
	//DFS_Recursion(V);
	DFS_Stack(V);
	cout << "\n";

	for (int i = 1; i <= N; i++)
		visited[i] = 0;


	//BFS
	queue<int> Q;
	Q.push(V);
	visited[V]++;

	while (!Q.empty())
	{
		int cur = Q.front();
		cout << cur << " ";
		Q.pop();

		for (int i = 0; i < Edge[cur].size(); i++)
		{
			if (visited[Edge[cur][i]] > 0)
				continue;

			Q.push(Edge[cur][i]);
			visited[Edge[cur][i]]++;
		}
	}

}
