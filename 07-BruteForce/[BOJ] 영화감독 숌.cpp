#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
	int iNum;
	scanf("%d", &iNum);
	int cnt = 1;
	int Number = 666;

	
	do 
	{
		string st = to_string(Number);
		if (st.find("666") != string::npos)
		{
			if (cnt == iNum)
			{
				printf("%d", stoi(st));
				return 0;
			}
			cnt++;
		}

		Number++;
	} while (cnt <= iNum);
	
	return 0;
}
