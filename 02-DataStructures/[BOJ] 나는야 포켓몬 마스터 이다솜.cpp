#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void)
{

	int N, M;
	cin >> N >> M;
	map<string, int> Pokemon;
    vector<string> Name(N);
	string Input_name;

	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < N; i++)
	{
		cin >> Name[i];
		Pokemon.insert(make_pair(Name[i], i));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> Input_name;
		if (isdigit(Input_name[0]) == 0) //문자일 때
		{
			cout << Pokemon[Input_name] + 1 << "\n";
		}
		else //숫자일 때
		{
			cout << Name[stoi(Input_name) - 1] << "\n";
		}
	}

	return 0;
}
