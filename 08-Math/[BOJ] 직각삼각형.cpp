#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;


int main(void)
{
	int a, b, c;


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (true)
	{
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;


		if (a * a + b * b == c * c ||
			a * a + c * c == b * b ||
			b * b + c * c == a * a)
		{
			cout << "right\n";
		}
		else
			cout << "wrong\n";
	}


	return 0;
}
