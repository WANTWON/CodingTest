#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
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

	stack<int> S;
	vector<char> Ans;
	int iNum = 0;
	bool Impossible = false;
	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;

		while (true)
		{
			if (!S.empty() && S.top() == Temp)
			{
				S.pop();
				Ans.push_back('-');
				break;
			}
			else if (iNum > Temp)
			{
				Impossible = true;
				break;
			}

			iNum++;
			S.push(iNum);
			Ans.push_back('+');

		}
	}

	if (Impossible)
		cout << "NO";
	else
	{
		for (int i = 0; i < Ans.size(); i++)
		{
			cout << Ans[i] << "\n";
		}
	}

	
	return 0;
}
