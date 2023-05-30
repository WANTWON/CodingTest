#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct UserTag
{
	int Age, Index;
	string Name;
}USER;


bool Sort(USER A, USER B)
{
	if (A.Age == B.Age)
		return A.Index < B.Index;

	return A.Age < B.Age;
}

int main(void)
{
	int iNum;
	cin>> iNum;
	vector<USER> vecUser(iNum);

	for (int i = 0; i < iNum; i++)
	{
		cin>> vecUser[i].Age >> vecUser[i].Name;
		vecUser[i].Index = i;
	}

	sort(vecUser.begin(), vecUser.end(), Sort);

	for (int i = 0; i < iNum; i++)
		cout << vecUser[i].Age << " " << vecUser[i].Name << "\n";

	return 0;
}
