#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
int N;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> arr(N);
	vector<int> unique_arr;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		unique_arr.push_back(arr[i]);
	}
	sort(unique_arr.begin(), unique_arr.end());
	unique_arr.erase(unique(unique_arr.begin(), unique_arr.end()), unique_arr.end());

	for (int i = 0; i < N; i++)
	{
		cout << lower_bound(unique_arr.begin(), unique_arr.end(), arr[i]) - unique_arr.begin() << " ";
	}

	
}
