#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;



int main(void)
{
	int fna, fnb;
	int c;
	int n0;
	bool isBigO = true;
	

	scanf("%d %d", &fna, &fnb);
	scanf("%d", &c);
	scanf("%d", &n0);

	for (int n = n0; n < 100; n++)
	{
		if (fna*n + fnb > c*n)
		{
			printf("%d", 0);
			isBigO = false;
			break;
		}
			
	}
	
	if(isBigO)
		printf("%d", 1);

	return 0;
}
