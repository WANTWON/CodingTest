#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> str;
	str.reserve(0);
	string s;
	string temp;
	cin >> s;
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
		{
			temp = s.substr(i, j+1);
			str.push_back(temp);
		}
	}

	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	cout << str.size();

	return 0;
}
