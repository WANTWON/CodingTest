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
int T, I, X, Y;
int board[1001][1001];
int visitedFire[1001][1001];
int visitedPlayer[1001][1001];




int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

int Firebfs(queue<pair<int, int>> fire)
{
	while (!fire.empty())
	{
		int curY = fire.front().first;
		int curX = fire.front().second;
		fire.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = curY + dirY[dir];
			int nx = curX + dirX[dir];

			if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
			if (board[ny][nx] == -1 || visitedFire[ny][nx] != 0) continue;

			fire.push({ ny, nx });
			visitedFire[ny][nx] = visitedFire[curY][curX] + 1;
		}
	}
	return 0;
}

int Playerbfs(queue<pair<int, int>> player)
{
	while (!player.empty())
	{
		int curY = player.front().first;
		int curX = player.front().second;
		player.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = curY + dirY[dir];
			int nx = curX + dirX[dir];

			if (ny < 0 || ny >= Y || nx < 0 || nx >= X)
			{
				return visitedPlayer[curY][curX];
			}
			if (board[ny][nx] == -1 || visitedPlayer[ny][nx] != 0) continue;
			if (visitedFire[ny][nx] != 0 && visitedFire[ny][nx] <= visitedPlayer[curY][curX] + 1) continue;

			player.push({ ny, nx });
			visitedPlayer[ny][nx] = visitedPlayer[curY][curX] + 1;
		}
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> X >> Y;

		queue<pair<int, int>> fire;
		queue<pair<int, int>> player;

		for (int i = 0; i < Y; i++)
		{
			fill(visitedFire[i], visitedFire[i] + X, 0);
			fill(visitedPlayer[i], visitedPlayer[i] + X, 0);

			for (int j = 0; j < X; j++)
			{
				board[i][j] = 0;
				char c;
				cin >> c;
				if (c == '@')
				{
					player.push({ i, j });
					visitedPlayer[i][j] = 1;
				}
				else if (c == '#')
				{
					board[i][j] = -1;
				}
				else if (c == '*')
				{
					fire.push({ i, j });
					visitedFire[i][j] = 1;
				}
			}
		}

		Firebfs(fire);
		int cnt = Playerbfs(player);
		if (cnt == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << cnt << endl;
	}
	return 0;
}
