#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int Graph[501][501];
bool Visited[501][501];
queue<pair<int,int>> Path;
vector<int> Result;

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0,-1, 0, 1 };
int cnt = 0;

int bfs(int x, int y)
{	

	cnt++;
	pair<int, int> Out = Path.front();
	Visited[Out.first][Out.second] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int X = Out.first + dirX[i];
		int Y = Out.second + dirY[i];

		if (X < 501 && X >= 0 && Y >= 0 && Y < 501)
		{
			if (Visited[X][Y] == false && Graph[X][Y] == 1)
			{
				Path.push(make_pair(X, Y));
				Visited[X][Y] = true;
			}
		}
	}

	Path.pop();
	if (Path.size() != 0)
		bfs(Path.front().first, Path.front().second);
	
	return cnt;
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	Result.reserve(0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Graph[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Graph[i][j] == 1 && Visited[i][j] == false)
			{
				Path.push(make_pair(i, j));
				Result.push_back(bfs(i, j));
				cnt = 0;
			}	
		}
	}
	

	int MAX = 0;
	for (int i = 0; i < Result.size(); i++)
	{
		if (MAX <= Result[i])
		{
			MAX = Result[i];
		}
	}

	cout << Result.size() << "\n";
	cout << MAX << "\n";
	

	return 0;
}
