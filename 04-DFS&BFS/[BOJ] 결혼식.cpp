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

int N, M, cnt = 0;
vector<int> graph[501];
int visited[501];

void bfs()
{
	queue<int> Q;
	Q.push(1);
	visited[1] = 1;

	while (!Q.empty())
	{
		int index = Q.front();
		Q.pop();

		for (auto edge : graph[index])
		{
			if (visited[edge] || visited[index] > 2) continue;

			cnt++;
			visited[edge] = visited[index] + 1;
			Q.push(edge);

		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--)
	{
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	bfs();
	cout << cnt << endl;

	return 0;
}
