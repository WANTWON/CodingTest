#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int cnt = 0; 
int Board[2][2] = { 0, };
vector<pair<int, int>> path;

int Check_N_Pos(int n, int r, int c)
{
	if (r < pow(2, n) / 2 && c < pow(2, n) / 2)
		return 1;
	else if (r < pow(2, n) / 2 && c >= pow(2, n) / 2)
		return 2;
	else if (r >= pow(2, n) / 2 && c < pow(2, n) / 2)
		return 3;
	else
		return 4;
}



int Func(int n, int r, int c)
{
	if (n == 0)
		return 0;

	int Half = pow(2, n) / 2;
	int N_Pos = Check_N_Pos(n, r, c);
	if (N_Pos == 1)
		return Func(n - 1, r, c);
	else if (N_Pos == 2)
		return Half*Half + Func(n - 1, r, c - Half);
	else if (N_Pos == 3)
		return Half*Half*2 + Func(n - 1, r-Half, c);
	else
		return Half*Half * 3 + Func(n - 1, r - Half, c - Half);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, C;
	cin >> N >> R >> C;


	cout << Func(N, R, C);

	return 0;
}
