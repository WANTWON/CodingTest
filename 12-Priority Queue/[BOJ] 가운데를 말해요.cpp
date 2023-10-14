#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>

using namespace std;

int N;
int tmp;
priority_queue<int, vector<int>, greater<>> minQ; //큰 수들 중 최소값
priority_queue<int> maxQ; //작은 수들 중 최대값

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	while (N--)
	{
		cin >> tmp;
		
		if (maxQ.size() <= minQ.size())
			maxQ.push(tmp);
		else
			minQ.push(tmp);

		if (!minQ.empty() && minQ.top() < maxQ.top())
		{
			//swap
			int mintop = minQ.top();
			int maxtop = maxQ.top();

			minQ.pop(); minQ.push(maxtop);
			maxQ.pop(); maxQ.push(mintop);
		}
		cout << maxQ.top() << "\n";
	}

	return 0;
}
