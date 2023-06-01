#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>

using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> Q;

	for (int i = 0; i < N; i++)
	{
		string str;
		int temp;

		cin >> str;

		if (str == "push_front")
		{
			cin >> temp;
			Q.push_front(temp);

		}
		else if (str == "push_back")
		{
			cin >> temp;
			Q.push_back(temp);
		}
		else if (str == "front")
		{
			if (Q.empty())
				cout << -1 << "\n";
			else
				cout << Q.front() << "\n";
		}
		else if (str == "back")
		{
			if (Q.empty())
				cout << -1 << "\n";
			else
				cout << Q.back() << "\n";
		}
		else if (str == "size")
		{
			cout << Q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << ((Q.empty() == true) ? 1 : 0) << "\n";
		}
		else if (str == "pop_front")
		{
			if (Q.empty())
				cout << -1 << "\n";
			else
			{
				cout << Q.front() << "\n";
				Q.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (Q.empty())
				cout << -1 << "\n";
			else
			{
				cout << Q.back() << "\n";
				Q.pop_back();
			}
		}
	}


	return 0;
}
