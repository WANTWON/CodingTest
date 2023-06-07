#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

vector<int> arr;
int ans[9];
int visited[9];

int N, M;

void BT(int Level)
{
	if (Level == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << "\n";
		return;
	}

	int Last = 0;
	for (int i = 0; i < N; i++)
	{
		if ( Last != arr[i] )
		{
			Last = arr[i];
			ans[Level] = arr[i];
			visited[i] = 1;
			BT(Level + 1);
			visited[i] = 0;
		}
			
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;

	for(int i =0; i < N; i++)
	{ 
		int Temp;
		cin >> Temp;
		arr.push_back(Temp);
	}
	sort(arr.begin(), arr.end());

	BT(0);

	return 0;
}
