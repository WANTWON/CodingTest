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

int N;

vector<int> graph[51];
int visited[51];
int score[51];


int dfs(int start)
{
	fill(visited, visited + N + 1, -1);
	queue<int> S;
	S.push(start);
	visited[start] = 0;

	while (!S.empty())
	{
		int cur = S.front();
		S.pop();

		for (auto edge : graph[cur])
		{
			if (visited[edge] != -1) continue;

			visited[edge] = visited[cur] + 1;
			S.push(edge);
		}
	}

	int max = *max_element(visited+1, visited +1+ N);
	if (max == 0) return 999;
	return max;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int A, B;
	while (true)
	{
		cin >> A >> B;

		if (A == -1 && B == -1)
			break;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}


	for (int i = 1; i <= N; i++)
	{
		int result = dfs(i);
		score[i] = result;
	}

	int min = *min_element(score + 1, score + 1 + N);

	vector<int> candidate;
	for (int i = 1; i <= N; i++)
	{
		if (score[i] == min)
		{
			candidate.push_back(i);
		}
	}

	cout << min << " " << candidate.size() << endl;
	for (int i = 0; i < candidate.size(); i++)
		cout << candidate[i] << " ";

	return 0;
}
