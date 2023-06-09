#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;

char Board1[9][9];
char Board2[9][9];
int N, M;

int DirX[4] = { 1, 0, -1, 0 };
int DirY[4] = { 0, 1 , 0, -1, };

vector<pair<int, int>> CCTV;
int Totalcnt = 0;

void BoardReset()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			Board2[i][j] = Board1[i][j];
}

void Watching(int Y, int X, int dir)
{
	int IndexX = X;
	int IndexY = Y;
	int Dir = dir % 4;

	while (1)
	{
		if (IndexX >= M || IndexX < 0 || IndexY >= N || IndexY < 0 || Board2[IndexY][IndexX] == '6')
			return;

		if (Board2[IndexY][IndexX] != '0')
		{
			IndexX += DirX[Dir];
			IndexY += DirY[Dir];
			continue;
		}

		Board2[IndexY][IndexX] = '#';

		IndexX += DirX[Dir];
		IndexY += DirY[Dir];

	}
	return;
}


void Play_CCTV(int Y, int X, char type, int dir)
{

	if (type == '1')
		Watching(Y, X, dir);
	else if (type == '2')
	{
		Watching(Y, X, dir);
		Watching(Y, X, dir + 2);
	}
	else if (type == '3')
	{
		Watching(Y, X, dir);
		Watching(Y, X, dir + 1);
	}
	else if (type == '4')
	{
		Watching(Y, X, dir);
		Watching(Y, X, dir + 1);
		Watching(Y, X, dir + 2);
	}
	else
	{
		Watching(Y, X, dir);
		Watching(Y, X, dir + 1);
		Watching(Y, X, dir + 2);
		Watching(Y, X, dir + 3);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int Temp;
			cin >> Temp;
			Board1[i][j] = Temp + 48;
			Board2[i][j] = Temp + 48;
			if (Board1[i][j] != '0' && Board1[i][j] != '6')
			{
				CCTV.push_back({ i, j });
			}

			if (Board1[i][j] == '0')
				Totalcnt++;

		}
	}

	for (int tmp = 0; tmp < (1 << (2 * CCTV.size())); tmp++)
	{
		BoardReset();
		int Brute = tmp;

		for (int j = 0; j < CCTV.size(); j++)
		{
			Play_CCTV(CCTV[j].first, CCTV[j].second, Board1[CCTV[j].first][CCTV[j].second], Brute % 4);
			Brute /= 4;
		}


		int val = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				val += (Board2[i][j] == '0');

		Totalcnt = min(Totalcnt, val);
	}


	cout << Totalcnt << "\n";
}
