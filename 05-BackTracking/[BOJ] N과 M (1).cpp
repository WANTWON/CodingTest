#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

#define MAX 9

using namespace std;

 int n, m;
 int arr[MAX];
 bool isvisited[MAX];

void BT(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (isvisited[i] == false)
		{
			isvisited[i] = true;
			arr[level] = i;
			BT(level + 1);
			isvisited[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	BT(0);

	return 0;
}

