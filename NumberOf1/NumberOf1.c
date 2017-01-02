#include <stdio.h>

int NumberOf1(int n)
{
	int count = 0;
	//必须无符号,否则左移可能变负数
	unsigned int flag = 1; 
	while(flag)
	{
		if(n & flag)
		  count++;

		flag = flag << 1;
	}
	return count;
}

//方法2
int _NumberOf1(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n - 1) & n;
	}
	return count;
}

int main()
{
	printf("%d\n", NumberOf1(0x7FFFFFFF));
	printf("%d\n", _NumberOf1(0x80000000));
	return 0;
}
