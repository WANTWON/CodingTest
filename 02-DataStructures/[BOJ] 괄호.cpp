#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stack>
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



	for (int i = 0; i < N; i++)
	{
		stack<char> S;
		string str;
		cin >> str;
		bool Possible = true;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '(')
				S.push('(');
			else if (str[j] == ')')
			{
				if (S.empty())
				{
					Possible = false;
					break;
				}
				else
				{
					S.pop();
				}
			}
		}

		if(Possible && S.empty())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
			
	}



	return 0;
}
