#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int Graph[1000][1002];
int Dist[1000][1002];

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0,-1 ,0, 1 };


queue<pair<int, int>> Q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TraversalCnt = 0;
	int m, n;
	cin >> m >> n;

	queue< pair<int, int>> Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Graph[i][j];
			if (Graph[i][j] == 0)
				Dist[i][j] = -1;
			else if (Graph[i][j] == 1)
			{
				Q.push({ i,j });
				Dist[i][j] = 0;
			}
		}

	}
  
	while (!Q.empty())
	{
		pair<int, int> Cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = Cur.first + dirX[i];
			int Y = Cur.second + dirY[i];

			if (X < 0 || X >= n || Y < 0 || Y >= m)
				continue;
			if (Graph[X][Y] == -1 || Dist[X][Y] >= 0)
				continue;

			Dist[X][Y] = Dist[Cur.first][Cur.second] + 1;
			Graph[X][Y] = 1;
			Q.push({ X,Y });

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Dist[i][j] == -1)
			{
				cout << -1 << "\n";
				return 0;
			}
			TraversalCnt = max(TraversalCnt, Dist[i][j]);
		}
	}
	cout << TraversalCnt << "\n";

	return 0;
}
