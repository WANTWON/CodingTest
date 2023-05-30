#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compareWith(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}


int main(void)
{
	int iNum;
	scanf("%d", &iNum);

	vector<string> vecStr;
	vecStr.reserve(0);

	for (int i = 0; i < iNum; ++i)
	{
		string str;
		cin >> str;
		
		if(find(vecStr.begin(), vecStr.end(), str) == vecStr.end())
			vecStr.push_back(str);

	}

	sort(vecStr.begin(), vecStr.end(), compareWith);
	
	for (int j = 0; j < (int)vecStr.size(); ++j)
	{
		printf("%s\n", vecStr[j].c_str());
	}

	return 0;
}
