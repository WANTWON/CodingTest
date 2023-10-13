#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int N, M;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> mycard;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		mycard.push_back(input);
	}

	sort(mycard.begin(), mycard.end());

	cin >> M;
	int num;
	for (int j = 0; j < M; j++)
	{
		cin >> num;
		cout << binary_search(mycard.begin(), mycard.end(), num) << " ";
	}
	return 0;
}
