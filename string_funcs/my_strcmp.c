#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
		  return 0;
		
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main()
{
	const char* p = "abcdef";
	const char* q = "abc";
	printf("%d\n", my_strcmp(p, q));
	return 0;
}
