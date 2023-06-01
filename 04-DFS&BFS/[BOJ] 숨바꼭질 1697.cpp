#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int Board[100001];




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	
	fill(Board, Board+100001, -1);
	Board[m] = 0;
	int cnt = 0;

	queue<int> Q;
	Q.push(m);

	while (Board[n] == -1)
	{
		int cur = Q.front();
		Q.pop();
		int dir[3] = { -1, 1, cur };
		for (int i = 0; i < 3; i++)
		{
			int Index = cur + dir[i];
			if (Index < 0 || Index >= 100001)
				continue;
			
			if (Board[Index] >= 0)
				continue;

				Board[Index] = Board[cur] + 1;
				Q.push(Index);
		}	
	}
	cout << Board[n];

	return 0;
}
