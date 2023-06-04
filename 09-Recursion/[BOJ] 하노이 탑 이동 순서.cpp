#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int cnt = 0; 
vector<pair<int, int>> path;

int Hanoi(int N, int start, int to, int var)
{
	cnt++;
	if (N == 1)
	{
		path.push_back({ start, to });
		return cnt;
	}
	Hanoi(N -1, start, var, to);
	path.push_back({ start, to });
	Hanoi(N -1, var, to, start );

	return cnt;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << Hanoi(N ,1, 3, 2) << "\n";

	for (int i = 0; i < path.size(); i++)
		cout << path[i].first << " " << path[i].second << "\n";

	return 0;
}
