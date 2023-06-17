#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;

int N, M, ans = 0;
vector<int> money;

void Func(int Index, int sum)
{
	if (sum > N)
		return;

	ans = max(sum, ans);

	for (int i = Index+1; i < M; i++)
	{
		if (sum + money[i] > N)
			continue;
		Func(i, sum + money[i]);
	}
		
}




int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		money.push_back(temp);
	}
	sort(money.begin(), money.end(), greater<>());

	for (int i = 0; i < M; i++)
		Func(i, money[i]);

	cout << ans;
}
