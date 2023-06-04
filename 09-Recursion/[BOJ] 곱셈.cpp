#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

long long Divide(long long A, long long B, long long C)
{
	if (B <= 1)
	{
		return A%C;
	}
	long long Val = Divide(A, B / 2, C);
	Val = Val*Val%C;

	
	if (B % 2 == 0)
		return Val;
	else
		return Val * A % C;
	
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B, C;
	cin >> A >> B >> C;


	long long ans = Divide(A, B, C);

	cout << ans;


	return 0;
}
