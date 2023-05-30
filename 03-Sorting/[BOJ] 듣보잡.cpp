#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> namelist;
	vector<string> Result;

	string s;

	for (int i = 0; i < N+M; i++)
	{
		cin >> s;
		namelist[s]++;

		if (namelist[s] > 1)
			Result.push_back(s);
	}

	sort(Result.begin(), Result.end());

	cout << Result.size() << "\n";
	for (int k = 0; k < Result.size(); k++)
		cout << Result[k] << "\n";


	return 0;
}
