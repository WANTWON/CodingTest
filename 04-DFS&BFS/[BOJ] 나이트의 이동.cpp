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


int T,I;
int visited[301][301];
pair<int, int> nightpos;
pair<int, int> destpos;

//나이트의 이동 좌표
int dirX[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dirY[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int bfs(int y, int x)
{
	queue<pair<int, int >> Q;
	visited[y][x] = 0;
	Q.push({ y, x });
	
	while (!Q.empty())
	{
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		if (curY == destpos.first && curX == destpos.second)
			return visited[curY][curX];

		for (int dir = 0; dir < 8; dir++)
		{
			int ny = curY + dirY[dir];
			int nx = curX + dirX[dir];

			if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
			if (visited[ny][nx] != -1) continue;

			visited[ny][nx] = visited[curY][curX] +1;
			Q.push({ ny, nx });
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
		cin >> I;
		
		for (int i = 0; i < I; i++)
			fill(visited[i], visited[i] + I, -1);

		cin >> nightpos.first >> nightpos.second;
		cin >> destpos.first >> destpos.second;
		cout << bfs(nightpos.first, nightpos.second) << endl;
	}

	return 0;
}
