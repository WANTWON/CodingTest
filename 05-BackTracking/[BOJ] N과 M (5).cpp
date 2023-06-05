#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;

vector<int> arr;
int visited[9];
int N, M;
int ans[9];

void BT(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}

	for (int j = 0; j < N; j++)
	{
		if (!visited[j])
		{
			ans[k] = arr[j];
			visited[j] = 1;
			BT(k + 1);
			visited[j] = 0;
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;

	
	for (int j = 0; j < N; j++)
	{
		int Temp;
		cin >> Temp;
		arr.push_back(Temp);
	}
	sort(arr.begin(), arr.end());

	BT(0);
	

}
