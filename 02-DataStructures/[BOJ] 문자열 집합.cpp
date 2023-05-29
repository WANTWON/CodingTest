#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	int N, M;
	int cnt = 0;
	cin >> N >> M;

	map<string, bool> s;
	string Temp;

	for (int i = 0; i < N; i++)
	{
		cin >> Temp;
		s[Temp] = true;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> Temp;
		if (s[Temp])
		{
			cnt++;
		}
			
	}

	cout << cnt <<endl;

	return 0;
}
