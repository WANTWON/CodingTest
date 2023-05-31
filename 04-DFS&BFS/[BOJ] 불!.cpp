#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

char Board[1002][1002];
int Dist[1002][1002]; //불
int Dist2[1002][1002];  //지훈

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0,-1 ,0, 1 };


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TraversalCnt = 0;
	int m, n;
	cin >> m >> n;

	int cnt = 0;
	queue< pair<int, int>> Jihoon;
	queue< pair<int, int>> Fire;
	

	for (int i = 0; i < m; i++)
	{
		string Input;
		cin >> Input;

		for (int j = 0; j < n; j++)
		{
			Board[i][j] = Input[j];
			if (Board[i][j] == 'J')
			{
				Jihoon.push({ i, j });
				Dist2[i][j] = 0;
			}	
			else if (Board[i][j] == 'F')
			{
				Fire.push({ i, j });
				Dist[i][j] = 0;
			}		
			else if (Board[i][j] == '.')
			{
				Dist[i][j] = -1;
				Dist2[i][j] = -1;
			}		
		}
	}

	//불에 대한 BFS
	while (!Fire.empty())
	{
		pair<int, int> curFire = Fire.front();
		Fire.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = curFire.first + dirX[i];
			int Y = curFire.second + dirY[i];

			if (X < 0 || X >= m || Y < 0 || Y >= n)
				continue;
			if (Board[X][Y] == '#' || Dist[X][Y] >= 0)
				continue;

			Dist[X][Y] = Dist[curFire.first][curFire.second] + 1;
			Fire.push({ X, Y });
		}
	}

	//지훈이에 대한 BFS
	while (!Jihoon.empty())
	{
		pair<int, int> curJihoon = Jihoon.front();
		Jihoon.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = curJihoon.first + dirX[i];
			int Y = curJihoon.second + dirY[i];

			if (X < 0 || X >= m || Y < 0 || Y >= n)
			{
				cout << Dist2[curJihoon.first][curJihoon.second] + 1 << "\n";
				return 0;
			}
			if (Board[X][Y] == '#' || Dist2[X][Y] >= 0)
				continue;
			if (Dist[X][Y] != -1 && Dist2[curJihoon.first][curJihoon.second]+1 >= Dist[X][Y])
				continue;

			Jihoon.push({ X, Y });
			Dist2[X][Y] = Dist2[curJihoon.first][curJihoon.second] + 1;		
		}
	}
	cout << "IMPOSSIBLE\n";

	return 0;
}
