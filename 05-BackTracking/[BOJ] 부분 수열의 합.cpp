#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

vector<int> arr;
int visited[21];
int cnt=0;
int N, M;

void BT(int Level, int Sum)
{
	if (Level == N)
	{
		if (Sum == M)
			cnt++;
		return;
	}

	
		
	BT(Level + 1, Sum);
	BT(Level + 1, Sum + arr[Level]);
			
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


	BT(0, 0);
	
	if (M == 0) cnt--;

	cout << cnt << "\n";

	return 0;
}
