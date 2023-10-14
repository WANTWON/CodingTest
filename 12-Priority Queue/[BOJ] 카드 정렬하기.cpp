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
priority_queue<int, vector<int>, greater<int>> vecNumber;

int MakeSumCase()
{
	int firstcmp, secondcmp, sum=0;
	while (vecNumber.size() > 1)
	{
		firstcmp = vecNumber.top(); vecNumber.pop();
		secondcmp = vecNumber.top(); vecNumber.pop();
		
		sum += firstcmp;
		sum += secondcmp;

		vecNumber.push(firstcmp + secondcmp);
	}

	return sum;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--)
	{
		cin >> tmp;
		vecNumber.push(tmp);
	}

	cout << MakeSumCase() << endl;

	return 0;
}
