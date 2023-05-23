#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#define MAX 15

using namespace std;

int n;
int cnt = 0;
set<int> colSet;
set<int> diagonalSetSum;
set<int> diagonalSetSub;

int arr[MAX][MAX] = { 0, };

void BT(int row)
{
	if (row == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (colSet.find(i) == colSet.end() && 
			diagonalSetSub.find(row-i) == diagonalSetSub.end() &&
			diagonalSetSum.find(row + i) == diagonalSetSum.end())
		{
			colSet.insert(i);
			diagonalSetSub.insert(row - i);
			diagonalSetSum.insert(row + i);
			arr[row][i] = 1;
			BT(row + 1);
			colSet.erase(i);
			diagonalSetSub.erase(row - i);
			diagonalSetSum.erase(row + i);
			arr[row][i] = 0;
		}

	}

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;
	BT(0);
	cout << cnt << "\n";

	return 0;
}
