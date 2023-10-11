#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int board[51][51];
bool visited[51][51];

int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

int T, M, N, K;
queue<pair<int, int>> Q;



void bfs(int x, int y)
{
	visited[x][y] = true;
	Q.push({ x,y });

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nextX = cur.first + dirX[dir];
			int nextY = cur.second + dirY[dir];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (visited[nextX][nextY] || board[nextX][nextY] == 0) continue;
			visited[nextX][nextY] = true;
			Q.push({ nextX, nextY });
		}
	}
}




int FindWarmNum()
{
	int warmCount = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0 || visited[i][j])
				continue;
			bfs(i, j);
			warmCount++;
		}
	}
	return warmCount;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		cout << FindWarmNum() << endl;
		for (int j = 0; j < N; j++)
		{
			fill(board[j], board[j] + M, 0);
			fill(visited[j], visited[j] + M, false);
		}

	}
}
