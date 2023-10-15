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
char arr[101][101];
int visited[101][101];

int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, 1, -1 };


void Check_Color(int y, int x)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!Q.empty())
	{
		int curY = Q.front().first;
		int curX = Q.front().second;
		char prevColor = arr[curY][curX];
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = curY + dirY[dir];
			int nx = curX + dirX[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (arr[ny][nx] != prevColor || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			Q.push(make_pair(ny, nx));
		}

	}

	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	int groupcnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (!visited[y][x])
			{
				Check_Color(y, x);
				groupcnt++;
			}

	cout << groupcnt << " ";

	for (int i = 0; i < N; i++)
		fill(visited[i], visited[i] + N, 0);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 'R') arr[i][j] = 'G';

	groupcnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (!visited[y][x])
			{
				Check_Color(y, x);
				groupcnt++;
			}

	cout << groupcnt << endl;

	return 0;
}
