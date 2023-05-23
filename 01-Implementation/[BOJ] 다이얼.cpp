#include <stdio.h>

using namespace std;

int main(void)
{
	int iAlphabet[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

	char Dial[16];

	scanf("%s", &Dial);

	int iSumTime = 0;
	int i = 0;

	while (Dial[i] != NULL)
	{
		iSumTime += iAlphabet[Dial[i] - 'A'];
		++i;
	}

	printf("%d\n", iSumTime);

	return 0;
}
