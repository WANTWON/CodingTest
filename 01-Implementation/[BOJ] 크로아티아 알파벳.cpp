#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void)
{
	string arrChroatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;

	getline(cin, str);

	int iPos = 0;
	
	for (int i = 0; i < 8; ++i)
	{
		while (str.find(arrChroatia[i]) != string::npos)
		{
			iPos = str.find(arrChroatia[i]);
			str.replace(str.find(arrChroatia[i], iPos), arrChroatia[i].length(), "#");
		} 
	}

	printf("%d", str.length());

	return 0;
}
