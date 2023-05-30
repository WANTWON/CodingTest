#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int Graph[101][101];
int Visited[101][101] = { 0, };

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0,-1, 0, 1 };

int n, m;
queue<pair<int, int>> Q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string Temp = "";
		cin >> Temp;
		for (int j = 0; j < m; j++)
		{
			Graph[i][j] = Temp[j] - 48;
		}
	}

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	Visited[0][0] = 1;

	while (!Q.empty())
	{
		pair<int, int> Front = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++)
		{
			int X = Front.first + dirX[k];
			int Y = Front.second + dirY[k];

			if (X < 0 || X> n || Y < 0 || Y > m)
				continue;
			if (Graph[X][Y] == 0 || Visited[X][Y] != 0)
				continue;

			Visited[X][Y] = Visited[Front.first][Front.second] +1;
			Q.push({ X, Y });
		}
	}

	cout << Visited[n - 1][m - 1] << "\n";
	return 0;
}
