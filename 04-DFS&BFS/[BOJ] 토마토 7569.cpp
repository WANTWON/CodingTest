#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int Graph[102][102][102];
int Dist[102][102][102] = { 0, };

int dirX[6] = { -1, 0, 0, 1, 0, 0 };
int dirY[6] = { 0,-1,0, 0, 1 , 0 };
int dirZ[6] = { 0,0,1, 0, 0 , -1};


queue<pair<int, int>> Q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TraversalCnt = 0;
	int m, n, h;
	cin >> m >> n >>h;
	
	queue<pair< int, pair<int, int>>> Q;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> Graph[k][i][j];
				if (Graph[k][i][j] == 0)
				{
					Dist[k][i][j] = -1;
				}
					
				if (Graph[k][i][j] == 1)
				{
					Q.push({ k,{ i,j } });
					Dist[k][i][j] = 0;
				}
			}
				
		}
	}


	while (!Q.empty())
	{
		pair< int, pair<int, int>> Cur = Q.front();
		Q.pop();

		for (int i = 0; i < 6; i++)
		{
			int X = Cur.second.first + dirX[i];
			int Y = Cur.second.second + dirY[i];
			int Z = Cur.first + dirZ[i];

			if (X < 0 || X >= n || Y <0 || Y >= m || Z <0 || Z >= h)
				continue;
			if (Graph[Z][X][Y] == -1 || Dist[Z][X][Y] >= 0)
				continue;

			Dist[Z][X][Y] = Dist[Cur.first][Cur.second.first][Cur.second.second] + 1;
			Graph[Z][X][Y] = 1;
			Q.push({ Z,{X,Y} });

		}
	}
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++) 
			{
				if (Dist[k][i][j] == -1)
				{
					cout << -1 << "\n";
					return 0;
				}
				TraversalCnt = max(TraversalCnt, Dist[k][i][j]);
			}
		}
	}
	cout << TraversalCnt << "\n";
	



	return 0;
}
