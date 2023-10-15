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

#define X second
#define Y first

using namespace std;
int BX, BY, K;
int board[101][101];
int visited[101][101];

int dirX[4] = { 1, -1, 0, 0 };
int dirY[4] = { 0,0,1, -1 };

vector<int> blocklist;

int bfs(int y, int x)
{
	queue<pair<int, int >> Q;
	Q.push({ y, x });
	visited[y][x] = true;

	int size = 1;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.Y + dirY[dir];
			int nx = cur.X + dirX[dir];

			if (ny < 0 || ny >= BY || nx < 0 || nx >= BX) continue;
			if (board[ny][nx] == -1 || visited[ny][nx]) continue;

			size++;
			visited[ny][nx] = true;
			Q.push({ ny, nx });
		}
	}
	return size;
}



void fillboard(pair<int, int> LD, pair<int, int> RU)
{
	for (int y = LD.Y; y < RU.Y; y++)
		for (int x = LD.X; x < RU.X; x++)
			board[y][x] = -1;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> BY >> BX >> K;

	pair<int, int> Ldown;
	pair<int, int> Rup;
	for (int i = 0; i < K; i++)
	{
		cin >> Ldown.X >> Ldown.Y;
		cin >> Rup.X >> Rup.Y;
		fillboard(Ldown, Rup);
	}

	for (int y = 0; y < BY; y++)
	{
		for (int x =0; x < BX; x++)
		{
			if (board[y][x] == -1 || visited[y][x]) continue;
			blocklist.push_back(bfs(y, x));
		}
	}

	cout << blocklist.size() << "\n";
	sort(blocklist.begin(), blocklist.end());
	for (int i = 0; i < blocklist.size(); i++)
		cout << blocklist[i] << " ";
	return 0;
}
