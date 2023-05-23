#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<int, int> set;

	int num;
	int cnt=0;

	for (int i = 0; i < N+M; i++)
	{
		cin >> num;
		set[num]++;

		if (set[num] > 1)
			cnt++;
	}

	cout << N+M-cnt*2 << "\n";


	return 0;
}
