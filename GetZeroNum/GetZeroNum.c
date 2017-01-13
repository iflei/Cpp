#include <stdio.h>

int Nof0(int n)
{
	int num = 0;
	int i, j;
	for(i = 5; i <= n; i+=5)
	{
		j = i;
		while(j % 5 == 0)
		{
			num++;
			j /= 5;
		}
	}

	return num;
}

int GetZeroNum(int n)
{
	int num = 0;
	while(n)
	{
		num += n/5;
		n /= 5;
	}

	return num;
}

int main()
{
	//5,10,15,20，各贡献一个，25贡献两个
	printf("%d\n", GetZeroNum(26));

	return 0;
}
