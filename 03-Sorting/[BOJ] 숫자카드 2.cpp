#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> Card;

int Count_Num(int num)
{
	vector<int>::iterator iter;
	
	int cnt = 0;

	cnt = (upper_bound(Card.begin(), Card.end(), num) - Card.begin()) - (lower_bound(Card.begin(), Card.end(), num) - Card.begin());
	return cnt;
}


int main(void)
{

	int N, M;
	vector<int> MyCard;

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int iNum;
		cin >> iNum;
		Card.push_back(iNum);
	}
	sort(Card.begin(), Card.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int iNum;
		cin >> iNum;
		MyCard.push_back(Count_Num(iNum));
		cout << MyCard[i] << " ";
	}

	return 0;
}
