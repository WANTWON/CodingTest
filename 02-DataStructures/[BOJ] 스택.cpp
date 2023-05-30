#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<int> v;


int main(void)
{
	v.reserve(0);
	
	int num, cnt;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		char s[10];
		cin >> s;
		

		if (!strcmp(s, "push"))
		{
			cin >> num;
			v.push_back(num);
		}
		else if (!strcmp(s, "pop"))
		{
			if(v.size() == 0)
				cout << -1 << "\n";
			else
			{
				if (v.size() == 0)
					cout << -1 << "\n";
				else
					cout << v.back() << "\n";
				v.pop_back();
				
			}
				
		}
		else if (!strcmp(s, "size"))
			cout << v.size() << "\n";
		else if (!strcmp(s, "empty"))
		{
			cout << v.empty() << "\n";
		}
		else if (!strcmp(s, "top"))
		{
			if (v.size() == 0)
				cout << -1 << "\n";
			else
				cout << v.back() << "\n";
		}
			
	}
	

	return 0;
}
